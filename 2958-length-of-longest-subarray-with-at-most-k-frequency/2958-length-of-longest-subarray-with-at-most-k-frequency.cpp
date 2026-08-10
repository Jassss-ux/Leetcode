class Solution {
public:
    int maxSubarrayLength(vector<int>& nums, int k) {
        int left = 0;
        int right = 0;
        int length =0;
        int n = nums.size();
        unordered_map<int , int> freq;
        while( right <n){
            freq[nums[right]]++;
            while( freq[nums[right]] > k){
                freq[nums[left]]--;
                left++;
            }

            if( freq[nums[right]]<=k){
                length = max( length, (right-left+1));
            }
            right++;
            
        }
        return length;
        
    }
};