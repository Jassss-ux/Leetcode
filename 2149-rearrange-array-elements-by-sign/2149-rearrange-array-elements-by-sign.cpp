class Solution {
public:
    vector<int> rearrangeArray(vector<int>& nums) {
        int pos = 0;
        int neg = 1;
        int n = nums.size();
        vector<int> ans(n);
        for (int val : nums) {
            if (val > 0) {
                ans[pos] = val;
                pos = pos + 2; // bcoz even indexes pe hi positive number ayega
                              // islye update aese hoga pos;
            } 
            else {
                ans[neg] = val;
                neg = neg + 2; // bcz har odd index pe ayega negative number
            }
        }
        return ans;
    }
};