class Solution {
public:
    bool canJump(vector<int>& nums) {

        // farthest = abhi tak hum maximum kis index tak pahunch sakte hain  // bcz hum hamesha start 0 index se hi kenge
        int farthest = 0;

        // Array ke har index par traverse karo
        for (int i = 0; i < nums.size(); i++) {

            // Agar current index hi reachable nahi hai,
            // to aage bhi nahi ja sakte
            if (i > farthest)  //index ki bada hogya hai max jump limit se toh sidha false
                return false;

            // Current index se jitni door jump laga sakte hain,
            // uske according farthest update karo
            farthest = max(farthest, i + nums[i]);  //index(i) + value at that index i(nums[i]) in dono ko add krne se pata chaelaga ki kinti door tak jump kr skhte h 

            // Agar farthest last index ya usse aage pahunch gaya,
            // to answer true hai
            if (farthest >= nums.size() - 1)   //n-1 size of the array
                return true;
        }

        // Agar poora loop chal gaya aur kahin bhi nahi fase,
        // to last index reachable hai
        return true;


        // int maxjump = 0;
        // int n = nums.size();
        // for( int i =0 ;i<n;i++){
        //     if( i > maxjump){
        //         return false;
        //     }

        //     maxjump = max(maxjump , i+nums[i]);

        //     if(maxjump>n-1){
        //         return true;
        //     }
        // }
        // return true;
    }
};