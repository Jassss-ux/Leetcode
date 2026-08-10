class Solution {
public:
    int findMaxConsecutiveOnes(vector<int>& nums) {
        int left = 0;
        int right = 0;
        int maxlen = INT_MIN;
        int n = nums.size();
        while( right<n){
            if( nums[right] != 1){
                left = right+1;
            }

            maxlen = max(maxlen, (right-left+1));

            right++;
        }
        return maxlen;
        
    }
};