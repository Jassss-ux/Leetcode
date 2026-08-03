class Solution {
public:
    int trap(vector<int>& height) {
        //BRUTE FORCE APPROACH O(n2)
        // int n = height.size();

        // int sum = 0;

        // for (int i = 0; i < n; i++) {
        //     int rightmax = INT_MIN; 
        //     int leftmax = INT_MIN;
        //     for (int j = 0; j <= i ; j++) {
        //         leftmax = max(leftmax, height[j]);
        //     }
        //     for (int j = i; j < n; j++) {
        //         rightmax = max(rightmax, height[j]);
        //     }
        //     int water = ((min(leftmax, rightmax))-height[i]);
        //     sum = sum + water;
        // }
        // return sum;

        //BETTER APPROACH WITH OPTIMIZED TIME COMPLEX AND NOT OPTIMIZED SPACE COMPLEX
        // int n = height.size();
        // vector<int>leftmax(n,0);
        // vector<int>rightmax(n,0);
        // leftmax[0] = height[0];
        // rightmax[n-1] = height[n-1];
        // for( int i = 1 ; i<n ;i++){
        //     leftmax[i] = max(leftmax[i-1] , height[i]);
        // }

        // for( int i = n-2; i>=0; i--){
        //     rightmax[i] = max(rightmax[i+1] , height[i]);
        // }

        // //formaula apply
        // int sum =0;
        // for( int i =0 ;i<n;i++){
        //     sum = sum +  min(leftmax[i] , rightmax[i]) - height[i];
        // }

        // return sum;

        //MOST OPTIMIZED APPROACH
        int sum = 0;
        int n = height.size();
        int leftpointer = 0;
        int rightpointer = n-1;
        int leftmax = 0;
        int rightmax =0 ;
        while( leftpointer < rightpointer){
            leftmax = max(leftmax, height[leftpointer]);  //leftmaxes value find at each cuurent value of hegiht i.e. hegiht[lftpointer]
            rightmax = max(rightmax, height[rightpointer]);  //rightmaxes find at each curr val of hegiht that is height[righpoiter]

            //check lmax is minium or rmax is minium the  apply formulas
            if(leftmax < rightmax){
                sum = sum + (leftmax - height[leftpointer]);
                leftpointer++;
            }
            else{
                sum = sum + (rightmax - height[rightpointer]);
                rightpointer--;
            }

        }
        return sum;
    }
};