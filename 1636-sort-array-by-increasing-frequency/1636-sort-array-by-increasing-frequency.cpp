class Solution {
public:
    vector<int> frequencySort(vector<int>& nums) {
        unordered_map<int,int> freq;
        for( int x: nums){
            freq[x]++;
        }
        sort(nums.begin(), nums.end(), [&](int a , int b){ //lamba function use hua h idhr sort krne ke liye
            if( freq[a] == freq[b]){
                return a>b;

            }
            return freq[a]< freq[b];
        });
        return nums;

        
    }
};