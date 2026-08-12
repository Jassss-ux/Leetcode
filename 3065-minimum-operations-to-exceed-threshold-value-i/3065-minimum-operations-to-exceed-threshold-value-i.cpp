class Solution {
public:
    int minOperations(vector<int>& nums, int k) {
        int n = nums.size();
        int count =0;
        for( int i =0;i<n;i++){ //idhr bas yeh dekhan h kitne smaller element h k se jitne smaller element honge utni bar unhe delete krna pdega and vohi count delete krna ka return krdo  idhr arrays se element delete krke pher count krne ki jrurut nhi hai 
            if( nums[i]<k){
                count++;
            }
        }
        return count;
        
    }
};