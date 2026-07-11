class Solution {
public:
    int sumOfSquares(vector<int>& nums) {
        int n = nums.size();
        int sum = 0;
        for( int i =1 ; i<=n;i++){
            if(n%i==0){
                int special = nums[i-1]*nums[i-1]; //hamara element 1 element on 0 index
                                                   // 2nd element on 1 index 
                                                   //3rd element on 2 index 
                                                   //pattern ban rha hai har element uske index -1 position pe hai 
                                                   //mtlb ki ith element = i-1 index
                sum = sum + special;
            }
        }
        return sum;
        
    }
};