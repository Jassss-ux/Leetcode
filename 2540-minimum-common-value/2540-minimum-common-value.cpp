class Solution {
public:
    int getCommon(vector<int>& nums1, vector<int>& nums2) {
        vector<int>ans;
        unordered_set<int>st( nums1.begin(), nums1.end()); // sare nums1 ke elemtns set ke andr add krdiye isse humne
        for( int val: nums2){
            if(st.count(val)){
                ans.push_back(val); //ans vector mein min element add krdiya
                st.erase(val); //jo element ik bari add hogya voh waps add na hoye isklye set se erease krdiya element
            }
        }
        if(ans.empty()){
            return -1;   //agr koi element common nhi hau tab humne krdiya -1 return 
        }
        return *min_element(ans.begin(),ans.end()); //min element return krdiya ans mein se
        
    }
};