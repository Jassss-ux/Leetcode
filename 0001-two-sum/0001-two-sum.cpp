class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        vector<int>ans;
        unordered_map<int,int> freq;
        for( int i = 0 ; i<nums.size(); i++){
            int first = nums[i];
            int second = target - nums[i];
            if( freq.find(second) != freq.end()){
                ans.push_back(i);
                ans.push_back(freq[second]);   //freq[second] ise second element ka index add hojyega map ke andr
                break;
            }
            freq[first]=i;
        }
        return ans;
        
    }
};