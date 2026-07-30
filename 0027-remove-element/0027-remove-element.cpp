class Solution {
public:
    int removeElement(vector<int>& nums, int val) {
        int count = 0;
        for( int i = 0;i <nums.size(); i++){
            if( nums[i] != val){
                nums[count] = nums[i]; // Copy every valid element to the next available position to keep all non-val elements together at the beginning.
                count++;
            }

        }
        return count;
        
    }
};