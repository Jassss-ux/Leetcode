class Solution {
public:
    int heightChecker(vector<int>& heights) {
        int n = heights.size();
        int count =0;
        vector<int>temp(n);  //idhr mereko apne temporary vector ka size dena pdega tabhi pta chalega na ki temp vector ki kitni lenght hogi jismein heights ki sari value copy hogi yeh nhi kiya toh runtime error ayega 
        // direct copy bhi banata skhta hai ismien aese krke
        // vector<int>temp = heights;     isse direct height ppura array copy hojyeaga temp mein
        for(int i = 0 ; i<n;i++){
            temp[i]=heights[i];
        }
        sort(temp.begin(),temp.end());

        for(int i =0 ;i<n;i++){
            if(heights[i]!=temp[i]){
                count++;
            }
        }
        return count;
        
    }
};