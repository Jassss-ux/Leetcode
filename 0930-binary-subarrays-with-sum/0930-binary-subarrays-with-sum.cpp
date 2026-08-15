class Solution {
public:
    int atmost(vector<int>& nums, int goal) {
        if (goal < 0) {
            return 0;
        }
        int n = nums.size();
        int left = 0;
        int right = 0;
        int count = 0;
        int sum = 0;
        while (right < n) {
            sum = sum + nums[right];
            while (sum > goal) {
                sum = sum - nums[left];
                left++;
            }
            count = count + (right - left + 1);

            right++;
        }
        return count;
    }
    int numSubarraysWithSum(vector<int>& nums, int goal) {
        int exactX = atmost(nums, goal) - atmost(nums, goal - 1);
        return exactX;
    }
};