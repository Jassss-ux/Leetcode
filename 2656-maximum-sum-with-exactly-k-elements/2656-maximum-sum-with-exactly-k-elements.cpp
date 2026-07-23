class Solution {
public:
    int maximizeSum(vector<int>& nums, int k) {
        int n = nums.size();
        int max1 = INT_MIN;
        for (int val : nums) {
            max1 = max(val, max1);
        }
        int sum = 0;
        for (int i = 0; i < k; i++) {

            sum = sum + max1;
            max1 = max1 + 1;
        }
        return sum;
    }
};