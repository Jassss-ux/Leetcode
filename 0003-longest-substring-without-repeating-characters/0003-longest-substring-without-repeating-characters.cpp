class Solution {
public:
    int lengthOfLongestSubstring(string s) {

        int ans = 0;

        // Window ka starting point
        int left = 0;

        // Current window ke characters ki frequency store karega
        unordered_map<char, int> freq;

        // i = window ka right end
        for (int i = 0; i < s.length(); i++) {

            // Current character ko window mein add karo
            freq[s[i]]++;

            while(freq[s[i]]>1){   // freq agr 1 se inc hgoyi toh left se element remove krnege and lefft ko aage inc krdenge jisse aage aur lambi substr find kr sake 
                freq[s[left]]--;
                left++;
            }

            /*
            ==========================================
                    DRY RUN: s = "abcad"
            ==========================================

            i = 0
            s[i] = 'a'

            freq:
            a -> 1

            Window:
            [a]
             ↑
            left = 0, i = 0

            Duplicate nahi hai.

            Window length:
            i - left + 1
            = 0 - 0 + 1
            = 1

            ans = max(0, 1)
                = 1
            */


            /*
            ==========================================
            i = 1
            s[i] = 'b'
            ==========================================

            Pehle:
            a -> 1

            Ab b add kiya:

            freq:
            a -> 1
            b -> 1

            Window:
            [a b]
             ↑ ↑
            left i

            left = 0
            i = 1

            Duplicate nahi hai.

            Window length:
            1 - 0 + 1
            = 2

            ans = max(1, 2)
                = 2
            */


            /*
            ==========================================
            i = 2
            s[i] = 'c'
            ==========================================

            freq:
            a -> 1
            b -> 1
            c -> 1

            Window:
            [a b c]
             ↑   ↑
            left  i

            Duplicate nahi hai.

            Window length:
            2 - 0 + 1
            = 3

            ans = max(2, 3)
                = 3
            */


            /*
            ==========================================
            i = 3
            s[i] = 'a'
            ==========================================

            Ab 'a' dobara aa gaya.

            freq:
            a -> 2   <-- DUPLICATE
            b -> 1
            c -> 1

            Window:
            [a b c a]
             ↑     ↑
            left   i

            Ab:

            while(freq[s[i]] > 1)

            while(freq['a'] > 1)
            while(2 > 1) -> TRUE

            ------------------------------------------
            while ke andar:

            freq[s[left]]--;

            left = 0
            s[left] = 'a'

            Isliye:

            freq['a']--
            a -> 2 - 1
            a -> 1

            Phir:

            left++;

            left = 1

            ------------------------------------------

            Ab:

            freq['a'] = 1

            while condition:

            freq['a'] > 1
            1 > 1 -> FALSE

            while stop.

            Current valid window:

              [b c a]
               ↑   ↑
              left i

            left = 1
            i = 3

            Window length:

            i - left + 1
            = 3 - 1 + 1
            = 3

            ans:

            max(3, 3)
            = 3
            */


            /*
            ==========================================
            i = 4
            s[i] = 'd'
            ==========================================

            'd' new character hai.

            freq:

            a -> 1
            b -> 1
            c -> 1
            d -> 1

            Current window:

              [b c a d]
               ↑     ↑
              left   i

            left = 1
            i = 4

            Koi duplicate nahi hai.

            Window length:

            i - left + 1
            = 4 - 1 + 1
            = 4

            ans:

            max(3, 4)
            = 4

            Final longest substring:

            "bcad"

            Length = 4
            */


            // Duplicate remove hone ke baad
            // current window ki length calculate kar rahe hain
            ans = max(ans, i - left + 1);
        }

        // Longest substring ki length return karo
        return ans;
    }
};