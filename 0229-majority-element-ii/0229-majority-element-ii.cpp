class Solution {
public:
    vector<int> majorityElement(vector<int>& nums) {  // optimize solution is bby using borre more algo see that later
        unordered_map<int, int> freq;
        int n = nums.size();
        for (int val : nums) {
            freq[val]++;
        }
        vector<int> ans;
        for (auto x : freq) {
            if (x.second > (n / 3)) {  //map hamra key, value pair store krta hai toh idhr hamra x.second = freq ( that is key) and x.first( is the value at that freq( key)) 
            ans.push_back(x.first);
            }
        }
        return ans;
    }
};