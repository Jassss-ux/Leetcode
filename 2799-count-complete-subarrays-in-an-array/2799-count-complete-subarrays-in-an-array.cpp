class Solution {
public:
    int countCompleteSubarrays(vector<int>& nums) {

        // Step 1:
        // Find the total number of unique elements in the entire array.
        // A complete subarray must contain all these unique elements.  and yeh unique elements honge SET ka size toh end mein size iislye likha hai and sorted pass krnge kyuki set mein unique element hi jynge toh sorted pass krne se irrevalnat travesal bhi save hojyega
        int total = unordered_set<int>(nums.begin(), nums.end()).size();

        // freq map stores the frequency of each element
        // present in the current sliding window.
        unordered_map<int, int> freq;

        int left = 0;       // Left pointer of sliding window
        int right = 0;      // Right pointer of sliding window
        int n = nums.size();

        // Stores the total number of complete subarrays.
        int count = 0;

        // Traverse the array using right pointer.
        while (right < n) {

            // Add the current element to the window
            // and increase its frequency.
            freq[nums[right]]++;

            // If the current window contains all the
            // unique elements, it is a complete subarray.
            while (freq.size() == total) {

                // If [left ... right] is complete,
                // then all subarrays formed by extending
                // this window towards the right will also
                // be complete.
                //
                // Number of such subarrays = n - right
                count += (n - right);

                // Remove the leftmost element from the window.
                freq[nums[left]]--;

                // If its frequency becomes 0,
                // it is no longer present in the current window.
                if (freq[nums[left]] == 0) {
                    freq.erase(nums[left]);
                }

                // Move the left pointer forward
                // to find more complete subarrays.
                left++;
            }

            // Expand the window by moving right pointer.
            right++;
        }

        // Return the total number of complete subarrays.
        return count;
    }
};