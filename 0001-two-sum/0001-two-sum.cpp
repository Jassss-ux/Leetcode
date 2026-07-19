class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        
        int n = nums.size();
        vector<int>ans;
        unordered_map<int,int>m;
        for( int i =0;i<n;i++){
            int first = nums[i];
            int second=target-nums[i];
            if(m.find(second)!=m.end()){
                ans.push_back(i);
                ans.push_back(m[second]);
                break;
            }
            m[first]=i;
        }
        return ans;

    }
};