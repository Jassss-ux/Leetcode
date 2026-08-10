class Solution {
public:
    int countGoodSubstrings(string s) {
        int n = s.length();
        int left = 0;
        int right = 0;
        int count = 0;

        unordered_map<char, int> freq;

        while (right < n) {

            // Current character ko window mein add karo
            freq[s[right]]++;

            // Window ki length 3 se zyada ho gayi
            // toh left se character remove karo
            while ((right - left + 1) > 3) {
                freq[s[left]]--;

                // Frequency 0 ho gayi toh map se erase karo
                if (freq[s[left]] == 0) {
                    freq.erase(s[left]);
                }

                left++;
            }

            // Length 3 hai aur teeno characters unique hain
            if ((right - left + 1) == 3 && freq.size() == 3) {
                count++;
            }

            right++;
        }

        return count;
    }
};