class Solution {
public:
    int largestRectangleArea(vector<int>& height) {
        int n= height.size();
        vector<int> left(n);
        vector<int> right(n);
        int currentarea = 0 ; //this willl calcuate area
        int ans =0 ; //this will check the max area of the possible reactangles areas
        stack<int> s; // left and right values dono ke liye use krnege yeh

        // right values callcuate
        for( int i = n-1; i>= 0 ;i--){
            while( s.size() > 0 && height[s.top()] >= height[i]){
                s.pop();
            }
            if( s.empty()){
                right[i] = n;
            }
            else{
                right[i] = s.top();
            }
            s.push(i);
        }

        // ab right values calcuate hogyi hai tab humko waps vohi same stack use krna hai toh usmein kuch values ho skhti h jo already exist krti ho toh uske liye humne phele stack ko khali krna pdega

        while(!s.empty()){
            s.pop();
        }


        // left smalller values calcuatre
        for( int i =0 ;i<n; i++){
            while(s.size() >0 && height[s.top()] >= height[i]){
                s.pop();
            }
            if(s.empty()){
                left[i] = -1;
            }
            else{
                left[i] = s.top();
            }
            s.push(i);
        }

        
        //final ans calcuation
        for( int i =0 ; i<n;i++){
            currentarea = height[i] * ( right[i] - left[i] -1);
            ans = max(ans,currentarea);
        }

        return ans;
        
    }
};