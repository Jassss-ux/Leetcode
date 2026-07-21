class Solution {
public:
    int minOperations(vector<int>& nums, int k) {
        int n = nums.size();
        int sum = 0;
        for( int val : nums){
            sum = sum + val;
        }
        return sum%k;
    }
};