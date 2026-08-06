class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        //BRUTE FORCCE
        // int n = num.size();
        // vector<int>ans;  
        // for( int i = 0 ; i< n; i++){
        //     for( int j = i+1 ; j<n;j++){
        //         if( num[i] + num[j] == target){
        //             ans.push_back(i+1);
        //             ans.push_back(j+1);
        //         }
        //     }  
        // }
        // return ans;
        
        //OPTIMAL SOLUTION BY TWO POINTER BEACUSE INPUT ARRAY IS SORTEED AND WE HAVE TO FIND THE SUM 
        int n = nums.size();
        int i = 0; 
        int j = n-1;
        vector<int>ans;
        while(i<j){
            if( nums[i] + nums[j] > target){
                j--;
            }
            else if( nums[i] + nums[j] < target){
                i++;
            }
            else{ // nums[i] + nums[j] == target tab postion ans mein add krdo position hoti hai index of i+1 and j+1
                ans.push_back(i+1); 
                ans.push_back(j+1);
                break;   // break krdiya kyuki humko answer pushback krne ke badh answer jab miljyega tab hum break krdenege twoo  pointer mein aesa hota hai 
            } 
        }
        return ans;
    }
};