class Solution {
public:
    double minimumAverage(vector<int>& nums) {
        sort(nums.begin(),nums.end());
        int n = nums.size();
        int i =0;
        int j =n-1;
        vector<float>ans;
        while(i<j){
            float avg = (nums[i]+nums[j])/2.0;
            ans.push_back(avg);
            i++;
            j--;
        }
        float min1 = INT_MAX;
        for(auto val : ans){
            min1 = min(val,min1);
        }
        return min1;

        
    }
};