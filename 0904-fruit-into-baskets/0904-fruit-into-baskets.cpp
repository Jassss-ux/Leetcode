class Solution {
public:
    int totalFruit(vector<int>& nums) {
        int left = 0;
        int right = 0;
        int maxlen = INT_MIN;
        unordered_map<int, int> freq;
        int n = nums.size();
        while (right < n) {
            freq[nums[right]]++;

            while (freq.size() > 2) {

                freq[nums[left]]--;

                if (freq[nums[left]] == 0) {
                    freq.erase(nums[left]);
                }
                left++;
            }

            
                maxlen = max(maxlen, right - left + 1);
            

            right++;
        }
        return maxlen;
    }
};