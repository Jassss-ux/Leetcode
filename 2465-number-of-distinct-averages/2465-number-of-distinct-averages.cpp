class Solution {
public:
    int distinctAverages(vector<int>& nums) {
        sort(nums.begin(),nums.end());
        int n = nums.size();
        int i =0;
        int j = n-1;
        int count=0;
        vector<float>ans;
        unordered_set<double>m;
        while(i<j){
            float avg = (nums[i]+nums[j])/2.0;
            ans.push_back(avg);
            m.insert(avg); //set ki property hoti hai ik bari element add hoga and agr  voh waps aya toh add NHI hoga 
            i++;
            j--;
        }
        return m.size();
        
    }
};