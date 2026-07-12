class Solution {
public:
    vector<int> pivotArray(vector<int>& nums, int pivot) {
        int n = nums.size();
        vector<int>ans;
        vector<int>temp;
        vector<int>equal;
        for( int i =0;i<n;i++){
            if(nums[i]<pivot){
                ans.push_back(nums[i]);
            }
            else if(nums[i]==pivot){
                equal.push_back(nums[i]);
            }
            else{
                temp.push_back(nums[i]);
            }

        }
        vector<int>final;
        for(int i =0;i<ans.size();i++){
            final.push_back(ans[i]);
        }
        for(int i =0 ;i <equal.size();i++){
            final.push_back(equal[i]);
        }
        for(int i =0;i<temp.size();i++){
            final.push_back(temp[i]);
        }

        return final;
        
    }
};