class Solution {
public:
    int maxProduct(vector<int>& nums) {
        // max product max and second max number ka hi ayega toh voh find krte hai and then unhe return krde | max and second max ko -1 se start krnge hum dummy value
        int max = -1;
        int max1 = -1;
        for( auto x: nums){
            if( x > max){
                max1 = max;
                max = x;
            }
            else if(x >max1){
                max1 = x;
            }
        }
        return (max-1)*(max1-1);

    
        
    }
};