class Solution {
public:
    vector<int> findMissingElements(vector<int>& nums) {
        int max1 = *max_element(nums.begin(),nums.end());  //to find max and min element without using loop trick
        int min1 = *min_element(nums.begin(), nums.end());
        vector<int>v;
        unordered_map<int,int>mp;
        for(int freq: nums){
            mp[freq]++;
        }
        for(int i=min1+1 ; i < max1;i++){
            if(mp.find(i)==mp.end()){
               v.push_back(i);
            }
        }
        return v;
        

    }
};