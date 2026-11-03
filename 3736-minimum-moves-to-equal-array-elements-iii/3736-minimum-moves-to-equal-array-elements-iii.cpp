class Solution {
public:
    int minMoves(vector<int>& nums) {
        int n = nums.size();
        int count = 0;
        int max1 = INT_MIN;
        for( int val : nums){
            max1 =  max(max1,val);
        }
        for( int i = 0; i<n;i++){

            //LOGIC : IDHR MTLB YEH HUA HAI KI HUMNE DEKHA PATTERN HAI MAX ELEMENT MEIN SE NUMS[I] KE ELEMENT MINUS KRHE HAI AND UNHEE ADD KRTE JYEGNE TOH HUMKO MINIUM NUMBER OF OPERATION MILJYENGE JO HUMEE CHAYE SARA ARRAY KO EQUAL KRNE KE LIYE
            //idhr hum count ke andr difference add krhe hai element ka jese 3-2 = 1 
            // count = 0 + (difference of max1-nums[i])  1 
            //count = 1
            //2nd iteration 3-1 = 2 
            //count (1) = 1+ (differnce of max1-nums[i])  2
            //count = 3  THIS IS OUR ANSWER
            count += max1 - nums[i];
        }
        return count;

        
    }
};