class Solution {
public:
    vector<int> findDuplicates(vector<int>& nums) {
        int n = nums.size();
        unordered_map<int,int> m;
        vector<int>ans;
        for( int i =0;i<n;i++){
            if(m.find(nums[i])!= m.end()){
               ans.push_back(nums[i]);
            }
            else{
                m.insert({nums[i], 1});//map hamehsa key value pair store krta hai toh key toh hamri voh hai jo hai hum array mein se number insert krhe hai jo unique rhegi har bari and 1  hamri value hai just as a dummy value jo samne rhegi hamesha kuch kam nhi h uska udhr but syntAX ke liye likhna pdega islye dummy vvalue 1 di gyi hai 
                
            }

        }
        return ans;
        
    }
};