class Solution {
public:
    int longestOnes(vector<int>& nums, int k) {
        int n = nums.size();
        int right = 0;
        int left = 0; 
        int length = 0;
        int zerocount = 0;
        while( right<n){
            if( nums[right] == 0){
                zerocount++;
            }
            while( zerocount > k){
                if(nums[left] == 0){
                    zerocount--;
                }

                left++;
            }

            
            length = max(length , right-left+1);
            

            right++;
        }
        return length;
    }
};