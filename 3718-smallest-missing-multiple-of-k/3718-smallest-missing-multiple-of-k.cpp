class Solution {
public:
    int missingMultiple(vector<int>& nums, int k) {
        unordered_set<int> s;

        // Store all elements
        for (int val : nums) {
            s.insert(val);
        }

        int multiple = 1;

        while (true) {
            int num = multiple * k;

            // If multiple of k is missing
            if (s.find(num) == s.end()) {
                return num;
            }

            multiple++;
        }
    }
};