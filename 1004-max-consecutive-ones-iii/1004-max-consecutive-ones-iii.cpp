class Solution {
public:
    int longestOnes(vector<int>& nums, int k) {

        int n = nums.size();

        int right = 0;
        int left = 0;

        int length = 0;
        int zerocount = 0;

        while (right < n) {

            // Agar current element 0 hai,
            // toh window mein zero count badhao
            if (nums[right] == 0) {
                zerocount++;
            }

            // Agar window mein k se zyada zeros hain,
            // toh left se elements remove karo
            if (zerocount > k) {

                // Agar left wala element 0 hai,
                // toh zero count decrease karo
                if (nums[left] == 0) {
                    zerocount--;
                }

                // Window ka left boundary aage move karo
                left++;
            }

            // Ab window valid hai (zerocount <= k)
            // Current window ki length calculate karo
            length = max(length, right - left + 1);

            // Right boundary ko aage move karo
            right++;
        }

        return length;
    }
};