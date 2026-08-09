
class Solution {
public:
    string reverseWords(string s) {

        int n = s.length();

        reverse(s.begin(), s.end());
        // Step 1: pehle puri string ko reverse kar lenge.


        string ans = "";
        // Ab final answer store karne ke liye ek ans string banayenge.


        for(int i = 0; i < n; i++) {

            string word = "";
            // Ab jo string reverse karke mili hai,
            // usmein har ek individual word ko reverse karke
            // word ke andar store karenge.


            while(i < n && s[i] != ' ') {

                // Jab tak space nahi milta tab tak hamara
                // individual word exist karega.
                // Isliye characters ko word ke andar add karte rahenge.

                word = word + s[i];

                i++;
                // Next character pe jaane ke liye i ko increment karenge.
            }
            reverse(word.begin() , word.end());

            if(word.length() > 0) {

                // Ab ans string ke andar apna word add karwa denge
                // with a single space, kyunki hume saari extra spaces
                // remove karni hain.

                ans = ans+ ' ' + word;

                
            }
        }
        return ans.substr(1); // substr fucntion humko ans string ke 1 index se print karwake dedega ans jisse hamra jo first jgh pe _pen_the jo hamra first space hai pen se phele voh print nhi hoga and correct answer milgya 
    }
};

