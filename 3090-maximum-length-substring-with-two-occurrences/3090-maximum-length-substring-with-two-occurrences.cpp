class Solution {
public:
    int maximumLengthSubstring(string s) {
        int left = 0;
        int right  =0;
        int n = s.length();
        int maxlen =0;
        unordered_map<char,int> freq;
        while( right < n){
            freq[s[right]]++;
            while(freq[s[right]] > 2){
                freq[s[left]]--;

                if( freq[s[left]] ==0 ){
                    freq.erase(s[left]);
                }
                left++;
            }
            if(freq[s[right]] <= 2){
                maxlen = max(maxlen, right-left+1);
            }
            right++;


        }

        return maxlen;
        
    }
};