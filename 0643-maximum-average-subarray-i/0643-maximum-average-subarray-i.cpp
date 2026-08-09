
class Solution {
public:
    double findMaxAverage(vector<int>& nums, int k) {

        int n = nums.size();

        // Left pointer window ka starting point hai
        int left = 0;

        // Right pointer window ko expand karega
        int right = 0;

        // Current window ka sum maintain karenge
        int sum = 0;

        // Maximum average store karne ke liye
        double maxavg = INT_MIN;


        // =========================================================
        // DRY RUN:
        // nums = [1, 12, -5, -6, 50, 3]
        // k = 4
        //
        // Humein size 4 ki window ka maximum average find karna hai.
        //
        // Initial:
        // left = 0
        // right = 0
        // sum = 0
        // maxavg = INT_MIN
        // =========================================================


        while (right < n) {

            // Right wala element window mein add karo
            sum = sum + nums[right];


            // =====================================================
            // DRY RUN - right = 0
            //
            // nums[right] = nums[0] = 1
            // sum = 0 + 1 = 1
            //
            // Window = [1]
            // Window size = 0 - 0 + 1 = 1
            //
            // 1 < k(4), so average calculate nahi hoga.
            // =====================================================


            // Agar window ka size k se bada ho gaya
            // toh left se element remove karo
            while ((right - left + 1) > k) {

                sum = sum - nums[left];

                // Left pointer ko aage move karo
                left++;
            }


            // Agar window ka size exactly k hai
            if ((right - left + 1) == k) {

                // Current window ka average calculate karo
                // (double) use kar rahe hain taaki decimal answer mile
                double avg = (double)sum / k;

                // Maximum average update karo
                maxavg = max(maxavg, avg);
            }


            // =====================================================
            // DRY RUN - right = 1
            //
            // nums[1] = 12
            // sum = 1 + 12 = 13
            //
            // Window = [1, 12]
            // Window size = 2
            //
            // Size 4 nahi hai, so average nahi niklega.
            // =====================================================


            // =====================================================
            // DRY RUN - right = 2
            //
            // nums[2] = -5
            // sum = 13 + (-5) = 8
            //
            // Window = [1, 12, -5]
            // Window size = 3
            //
            // Size 4 nahi hai.
            // =====================================================


            // =====================================================
            // DRY RUN - right = 3
            //
            // nums[3] = -6
            // sum = 8 + (-6) = 2
            //
            // Window = [1, 12, -5, -6]
            // Window size = 4
            //
            // Exactly k elements hain.
            //
            // avg = 2 / 4 = 0.5
            // maxavg = 0.5
            // =====================================================


            // =====================================================
            // DRY RUN - right = 4
            //
            // nums[4] = 50
            // sum = 2 + 50 = 52
            //
            // Temporary window:
            // [1, 12, -5, -6, 50]
            //
            // Window size = 5
            // But k = 4, so window too large hai.
            //
            // Remove nums[left]:
            // nums[0] = 1
            //
            // sum = 52 - 1 = 51
            // left = 1
            //
            // Ab window:
            // [12, -5, -6, 50]
            //
            // Window size = 4
            //
            // avg = 51 / 4 = 12.75
            //
            // maxavg = max(0.5, 12.75)
            //        = 12.75
            // =====================================================


            // =====================================================
            // DRY RUN - right = 5
            //
            // nums[5] = 3
            // sum = 51 + 3 = 54
            //
            // Temporary window:
            // [12, -5, -6, 50, 3]
            //
            // Window size = 5
            // Again window too large hai.
            //
            // Remove nums[left]:
            // nums[1] = 12
            //
            // sum = 54 - 12 = 42
            // left = 2
            //
            // Current window:
            // [-5, -6, 50, 3]
            //
            // Window size = 4
            //
            // avg = 42 / 4 = 10.5
            //
            // maxavg = max(12.75, 10.5)
            //        = 12.75
            // =====================================================


            // Right pointer ko next element par move karo
            right++;
        }


        // Final maximum average = 12.75
        return maxavg;
    }
};

