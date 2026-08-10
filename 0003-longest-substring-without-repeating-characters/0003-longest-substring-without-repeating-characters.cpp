class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        unordered_map<char,int> freq;
        int left = 0; 
        int right = 0;
        int length = 0;
        int n = s.length();
        while( right <n ){
            freq[s[right]]++;

            while( freq[s[right]] > 1){
                freq[s[left]]--;
                left++;
                

            }
            length = max( length , (right-left+1));
            right++;

        }
        return length;

        
    }
};