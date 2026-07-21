class Solution {
public:
    int minPairSum(vector<int>& nums) {
        int n =  nums.size();
        sort(nums.begin(),nums.end()); //array ko sort krha jisse optimal pair mile yeh optimal pair hoga har arrya m bar bar largest and smallest number ka pair jisko two pointer se bangye
        int i =0;
        int j =n-1;
        int max1 = 0;
        while(i<j){
            int pairsum = nums[i]+nums[j];
            max1 =  max(pairsum,max1);
            i++;
            j--;
        }
        return max1;
        
    }
};