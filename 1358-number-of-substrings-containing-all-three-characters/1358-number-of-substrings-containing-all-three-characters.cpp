class Solution {
public:
    int numberOfSubstrings(string s) {
        unordered_map<char,int>freq;
        int n = s.length();
        int left = 0 ;
        int right = 0;
        int count =0;
        while(right < n){
            freq[s[right]]++;
            while( freq.size() ==3){
                count = count + (n - right);
                freq[s[left]]--;
                if(freq[s[left]] == 0){
                    freq.erase(s[left]);
                }
                left++;
            }
            right++;
        }
        return count;
        
    }
};