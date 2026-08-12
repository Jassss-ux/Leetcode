class Solution {
public:
    int numJewelsInStones(string jewels, string stones) {
        unordered_set<char> Set;
        //Sabse pehle jewels ke saare characters ko set mein store karenge, kyunki set unique elements store karta hai. Uske baad stones ko traverse karke count() function se check karenge ki current character set mein present hai ya nahi. Agar present hai, toh count ko increment kar denge.

        // Saare jewel characters ko set mein store kar rahe hain
        for (char ch : jewels) {
            Set.insert(ch);
        }

        int count = 0;

        // Stones ke har character ko check karo
        for (char ch : stones) {
            // Agar current stone jewel hai
            if (Set.count(ch)) {
                count++;
            }
        }

        return count;
    }
};