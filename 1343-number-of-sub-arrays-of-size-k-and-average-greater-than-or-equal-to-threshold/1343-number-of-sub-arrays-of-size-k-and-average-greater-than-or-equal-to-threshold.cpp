class Solution {
public:
    int numOfSubarrays(vector<int>& nums, int k, int threshold) {

        int n = nums.size();

        // Left aur right pointers sliding window ko maintain karenge
        int left = 0;
        int right = 0;

        // Current window ka sum store karega
        int sum = 0;

        // Required subarrays ka count
        int count = 0;

        // Mathematically:
        // Average >= threshold
        // sum / k >= threshold
        // sum >= k * threshold
        //
        // Isliye baar-baar average calculate karne ki
        // zarurat nahi hai, hum directly sum ko target se compare karenge.
        int target = k * threshold;

        // Right pointer se window ko traverse karenge
        while (right < n) {

            // Current element ko window ke sum mein add karo
            sum += nums[right];

            // Check karo ki window ka size exactly k ho gaya hai
            if (right - left + 1 == k) {

                // Agar current window ka sum target se
                // bada ya equal hai, iska average threshold
                // se bada ya equal hoga.
                //
                // Matlab humein required subarray mil gaya.
                if (sum >= target) {
                    count++;
                }

                // Ab window ko next position par shift karna hai.
                // Isliye leftmost element ko sum se remove karo.
                sum -= nums[left];

                // Left pointer ko ek step aage move karo
                left++;
            }

            // Right pointer ko next element par move karo
            right++;
        }

        // Total valid subarrays return karo
        return count;
    }
};