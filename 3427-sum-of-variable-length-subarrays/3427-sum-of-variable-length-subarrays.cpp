class Solution {
public:
    int subarraySum(vector<int>& nums) {
        int n = nums.size();
        int ans = 0;

        for (int i = 0; i < n; i++) {

            int start = max(0, i - nums[i]); //given in quesstion condition

            for (int j = start; j <= i; j++) {
                ans += nums[j];    // idhr start se leke i tak  j loop chalega bcz humko bol rkha hai subarray start se i tak ja rha hai question mein
                
            }
        }

        return ans;
    }
};