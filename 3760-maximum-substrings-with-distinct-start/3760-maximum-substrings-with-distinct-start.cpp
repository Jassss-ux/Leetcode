class Solution {
public:
    int maxDistinct(string s) {
        unordered_set<char> st;

        // Har character ko set mein insert karo
        // Set duplicate characters ko automatically ignore karta hai
        for (char ch : s) {
            st.insert(ch);
        }

        // Set mein jitne distinct characters hain,
        // utne maximum substrings bana sakte hain
        return st.size();
    }
};