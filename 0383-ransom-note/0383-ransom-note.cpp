class Solution {
public:
    bool canConstruct(string ransomNote, string magazine) {

        // Magazine ke characters ka frequency map banayenge.
        // Isko hum available "stock" samajh sakte hain.
        unordered_map<char, int> freq;

        /*
        =====================================================
        TRUE EXAMPLE
        =====================================================

        ransomNote = "aabb"
        magazine   = "aabbbc"

        Magazine ka stock:

        a -> 2
        b -> 3
        c -> 1

        Ab ransomNote = "aabb" banayenge:

        'a' -> available hai
               freq['a'] = 2 -> 1

        'a' -> available hai
               freq['a'] = 1 -> 0

        'b' -> available hai
               freq['b'] = 3 -> 2

        'b' -> available hai
               freq['b'] = 2 -> 1

        Saare characters mil gaye
        => return true
        */

        // Magazine ke har character ko frequency map mein add karo
        for (char ch : magazine) {
            freq[ch]++;
        }

        /*
        =====================================================
        FALSE EXAMPLE
        =====================================================

        ransomNote = "aabbc"
        magazine   = "aabbd"

        Magazine ka stock:

        a -> 2
        b -> 2
        d -> 1

        Ab ransomNote = "aabbc" banayenge:

        'a' -> available
               freq['a'] = 2 -> 1

        'a' -> available
               freq['a'] = 1 -> 0

        'b' -> available
               freq['b'] = 2 -> 1

        'b' -> available
               freq['b'] = 1 -> 0

        'c' -> available nahi hai!
               freq['c'] = 0

        Isliye:
        if(freq['c'] == 0)
            return false;

        => return false
        */

        // RansomNote ke har character ko ek-ek karke check karenge
        for (char ch : ransomNote) {

            // Agar character ka stock 0 hai,
            // matlab required character available nahi hai
            if (freq[ch] == 0) {
                return false;
            }

            // Character use kar liya,
            // isliye uska stock 1 se decrease kar do
            freq[ch]--;
        }

        // Agar ransomNote ke saare characters mil gaye,
        // toh ransomNote construct ho sakta hai
        return true;
    }
};