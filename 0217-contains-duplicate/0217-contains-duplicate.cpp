class Solution {
public:
    bool containsDuplicate(vector<int>& nums) {
        unordered_map<int,int> freq;
        int n = nums.size();
        for( int val: nums){
            freq[val]++;
            if(freq[val] > 1){
                return true;
            }
        }
        

        return false;       
    }
};