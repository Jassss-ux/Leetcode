class Solution {
public:
    vector<int> intersection(vector<int>& nums1, vector<int>& nums2) {

        //  // BRUTE FORCE TC = O(N x M)
        // int n = nums1.size();
        // int m = nums2.size();
        // unordered_set<int>st;
        // vector<int>ans;
        // for( int i = 0 ; i<n;i++){
        //     for( int j = 0 ;j<m;j++){
        //         if(nums1[i] == nums2[j]){
        //             if(!st.count(nums1[i])){
        //                 st.insert(nums1[i]);
        //                 ans.push_back(nums1[i]);
        //             }
        //         }
        //     }
        // }
        // return ans;


        //optimal soolution
        // unordered_set<int> st ( nums1.begin(), nums1.end());
        // vector<int>ans;
        // for( int val : nums2){
        //     if(st.count(val)){
        //         ans.push_back(val);
        //         st.erase(val);  //erase dupplicate ellement from the set 
        //     }
        // }

        // return ans;

        //OPTIMAL SOLUTINO WITH DRY RUN

        // Store all unique elements of nums1 in a hash set.
        // Example:
        // nums1 = [1,2,2,1]
        // st = {1,2}
        unordered_set<int> st(nums1.begin(), nums1.end());

        vector<int> ans;

        // Traverse nums2 and check if each element exists in nums1.
        for (int val : nums2) {

            // If element is found in the set, it is common to both arrays.
            if (st.count(val)) {

                // Add the common element to the answer.
                ans.push_back(val);

                // Remove it from the set so it is not added again.
                // Example:
                // nums2 = [2,2]
                //
                // First 2:
                // st = {1,2}
                // ans = [2]
                // erase(2) --> st = {1}
                //
                // Second 2:
                // st.count(2) = 0
                // so it is skipped.
                st.erase(val);
            }
        }

        return ans;

        
    }
};