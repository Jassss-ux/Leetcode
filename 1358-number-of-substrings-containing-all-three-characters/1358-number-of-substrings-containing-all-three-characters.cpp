class Solution {
public:
    int numberOfSubstrings(string s) {
        //     unordered_map<char, int> freq;
        //     int n = s.length();
        //     int left = 0;
        //     int count = 0;

        //     for (int right = 0; right < n; right++) {

        //         freq[s[right] - 'a']++;

        //         // Jab current window mein a, b, c teeno aa jaye
        //         while (freq.size() == 3) {

        //             // DRY RUN:
        //             // right = 2, n = 6
        //             // count += (6 - 2) = 4
        //             //us point se us right pointer se n tak ki valid sari
        //             substring ko count krne ke liye coount + (n-right) N toh
        //             harma size hogya string ka and right pointer voh jgh jidr
        //             abhi point krha hoga and us point se leke end tak hi sari
        //             substring add hojyegi count mein
        //             // "abc", "abca", "abcab", "abcabc"
        //             // Total 4 valid substrings

        //             count += (n - right);

        //             freq[s[left] - 'a']--;

        //             if (freq[s[left]] == 0) {
        //                 freq.erase(s[left]);
        //             }

        //             left++;
        //         }
        //     }

        //     return count;
        // }

        // MORE OPITMIZED CODE BY USNIG AND FREQUENCY ARRAY BECUARSE WE HAVE
        // ONLY 3 ELEMENTS IN THE ARRAY THAT WE HAVE TO CHECK AND ALL ARE LOWER
        // CASE

        vector<int> freq(3, 0);
        int n = s.length();
        int left = 0;
        int count = 0;
        int right = 0;
        while (right < n) {
            freq[s[right] - 'a']++;
            while (freq[0] > 0 && freq[1] > 0 && freq[2] > 0) {
                count = count + (n - right);
                freq[s[left] - 'a']--;
                left++;
            }
            right++;
        }

        return count;
    };
};