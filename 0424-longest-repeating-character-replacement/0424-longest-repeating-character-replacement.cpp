class Solution {
public:
    int characterReplacement(string s, int k) {
        int left = 0;
        int right = 0;
        int maxlen = 0;
        int maxfreq = 0;

        unordered_map<char, int> freq;
        int n = s.length();
        while (right < n) {
            freq[s[right]]++;
            maxfreq = max(maxfreq, freq[s[right]]);

            while ((right - left + 1) - maxfreq > k) {
                freq[s[left]]--;

                if (freq[s[left]] == 0) {
                    freq.erase(s[left]);
                }

                left++;
            }

            maxlen = max(maxlen, (right - left + 1));

            right++;
        }
        return maxlen;
    }
};