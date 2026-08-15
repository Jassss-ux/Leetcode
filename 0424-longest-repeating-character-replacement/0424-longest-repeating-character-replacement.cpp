class Solution {
public:
    int characterReplacement(string s, int k) {

        // 'left' and 'right' represent the boundaries of our sliding window
        int left = 0;
        int right = 0;

        // Stores the maximum length of a valid window found so far
        int maxlen = 0;

        // Stores the highest frequency of any single character
        // present in the current/previous windows
        int maxfreq = 0;

        // Frequency array for 26 uppercase English letters
        // hash[0] = frequency of 'A'
        // hash[1] = frequency of 'B'
        // ...
        // hash[25] = frequency of 'Z'
        vector<int> hash(26, 0);

        int n = s.length();

        // Expand the sliding window using 'right'
        while (right < n) {

            // Increase the frequency of the current character
            // Example: if s[right] = 'A', then hash[0]++
            hash[s[right] - 'A']++;

            // Update the maximum frequency in the window
            // We need this to know which character occurs the most
            maxfreq = max(maxfreq, hash[s[right] - 'A']);

            // Number of characters that need to be replaced is:
            // Window size - frequency of most frequent character
            //
            // If replacements required > k, the current window
            // is invalid, so we shrink it from the left.
            if ((right - left + 1) - maxfreq > k) {

                // Remove the leftmost character from the window
                hash[s[left] - 'A']--;

                // Move left forward to make the window smaller
                left++;
            }

            // The current window is valid, so update the maximum length
            maxlen = max(maxlen, right - left + 1);

            // Move right forward to include the next character
            right++;
        }

        // Return the longest substring that can be made
        // of the same character using at most k replacements
        return maxlen;
    }
};