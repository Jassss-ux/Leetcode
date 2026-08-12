class Solution {
public:
    vector<vector<int>> threeSum(vector<int>& nums) {
        int n = nums.size();
        vector<vector<int>> ans;

        // Array ko sort karne se:
        // 1. Two-pointer approach possible hoti hai
        // 2. Duplicate elements ko easily skip kar sakte hain
        sort(nums.begin(), nums.end());

        // Har element ko first element (i) maan kar
        // baaki 2 elements (j, k) se pair find karenge
        for (int i = 0; i < n; i++) {

            // Agar current element previous element ke same hai,
            // toh same triplet dobara generate hoga.
            // Isliye duplicate i ko skip kar do.
            if (i > 0 && nums[i] == nums[i - 1])
                continue;

            // j left pointer hai, jo i ke next element se start hoga
            int j = i + 1;

            // k right pointer hai, jo array ke last element se start hoga
            int k = n - 1;

            // Jab tak dono pointers ek dusre se cross nahi karte
            while (j < k) {

                // Teen elements ka sum calculate karo
                int sum = nums[i] + nums[j] + nums[k];

                // Agar sum 0 se chhota hai,
                // toh sum ko increase karna padega.
                // Sorted array mein j ko aage badhane se value increase hogi.
                if (sum < 0) {
                    j++;

                // Agar sum 0 se bada hai,
                // toh sum ko decrease karna padega.
                // k ko peeche lane se value decrease hogi.
                } else if (sum > 0) {
                    k--;

                } else {

                    // Sum exactly 0 hai,
                    // toh valid triplet mil gaya.
                    ans.push_back({nums[i], nums[j], nums[k]});

                    // Next possible pair ke liye dono pointers move karo
                    j++;
                    k--;

                    // Duplicate j values ko skip karo,
                    // taaki same triplet dobara add na ho.
                    while (j < k && nums[j] == nums[j - 1]) {
                        j++;
                    }
                }
            }
        }

        // Saare unique triplets return karo
        return ans;
    }
};