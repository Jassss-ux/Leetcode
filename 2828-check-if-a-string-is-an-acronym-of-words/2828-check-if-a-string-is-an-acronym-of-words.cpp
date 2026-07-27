class Solution {
public:
    bool isAcronym(vector<string>& words, string s) {
        //jab humne array ke andr jo string de rkhi hoti hai uske first element add krne hote toh uske liye ik new string banalo empty and har ik word ka frist element ik loop lagake add krte rho ik for each loop lagake and 0 index pe add krte time zero index lena hota hai  
        string ans ="";
        for( auto x : words)
        {
            ans = ans+x[0];
        }

        return ans==s;
    }
};