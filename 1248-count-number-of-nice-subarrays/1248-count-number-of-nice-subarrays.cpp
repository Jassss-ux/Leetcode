class Solution {
public:

    int atmost(vector<int>& nums, int k) {

        int n = nums.size();
        int left = 0;
        int right = 0;

        // Number of odd elements in current window
        int oddcount = 0;

        // Number of subarrays having at most k odd numbers
        int count = 0;

        while (right < n) {

            // If current number is odd,
            // increase the odd count
            if (nums[right] % 2 != 0) {
                oddcount++;
            }

            // If window has more than k odd numbers,
            // shrink the window from the left
            while (oddcount > k) {

                // If the leftmost element is odd,
                // remove it from odd count
                if (nums[left] % 2 != 0) {
                    oddcount--;
                }

                left++;
            }

            // All subarrays ending at 'right'
            // starting from left to right have
            // at most k odd numbers.
            count += right - left + 1;

            right++;
        }

        return count;
    }

    int numberOfSubarrays(vector<int>& nums, int k) {

        // Exactly k odd numbers =
        // atMost(k) - atMost(k - 1)
        return atmost(nums, k) - atmost(nums, k - 1);
    }
};