
class Solution {
public:
    bool isAnagram(string s, string t) {

        // Agar dono strings ki length different hai,
        // toh woh anagram ho hi nahi sakti
        if (s.length() != t.length()) {
            return false;
        }

        // Ek hi map use karenge frequency difference track karne ke liye
        unordered_map<char, int> freq;

        // s ke har character ki frequency increase (+1) karenge
        // Example: s = "aabbc"
        // freq[a] = 2, freq[b] = 2, freq[c] = 1
        for (char i : s) {
            freq[i]++;
        }

        // t ke har character ki frequency decrease (-1) karenge
        // Agar t mein bhi same characters same frequency mein hain,
        // toh saari frequencies eventually 0 ho jayengi
        //
        // Isliye:
        // s ke characters -> +1
        // t ke characters -> -1
        //
        // Same frequency -> balance = 0
        for (char j : t) {
            freq[j]--;
        }

        // Ab check karenge ki har character ki frequency 0 hai ya nahi
        // Agar koi frequency 0 nahi hai,
        // iska matlab dono strings mein characters ki frequency different hai
        for (auto val : freq) {

            // val.second = character ki final frequency/difference
            if (val.second != 0) {
                return false;
            }
        }

        // Agar sabhi characters ki frequency 0 hai,
        // toh dono strings anagram hain
        return true;
    }
};
