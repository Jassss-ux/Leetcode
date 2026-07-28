class Solution {
public:
    vector<bool> kidsWithCandies(vector<int>& num, int extraCandies) {
        vector<bool> ans;  //har ik bache ko extracandie add krdi usse phele hume max of array find krna pdega bcz hume check krna hai ki voh kid ke pass candies max se jyda hui tabhi true warna false;
        int n = num.size();
        int value = 0;
        int max1 = INT_MIN;
        for (int val : num) {
            max1 = max(val, max1);
        }
        for (int i = 0; i < n; i++) {

            if (num[i] + extraCandies >= max1) {
                ans.push_back(true);
            } else {
                ans.push_back(false);
            }
        }
        return ans;
    }
};