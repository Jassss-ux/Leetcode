class Solution {
public:
    int sumDivisibleByK(vector<int>& nums, int k) {
        unordered_map<int,int> freq;    //freq ka logic learn kro yeh unordered map se hi frequncey nikalti hai har element ki 

        for( int x: nums){
            freq[x]++;
        }

        int sum = 0;
        for(int x: nums){
            if(freq[x] % k==0){
                sum = sum + x;
            }
        }
        return sum;
        
    }
};