class Solution {
public:
    bool check(vector<int>& bloomday , int m , int k , int mid){
        int flower = 0;
        int bouquet = 0 ;
        for( int val : bloomday){   //val is the travesing varible on blooomday array
            if(val <= mid){
                flower++; //this means hamre flower bloom hote jrhe hai and hum count krte jarhe hai ki kinte fflower blooom ho chuke hai 

                  if( flower == k){
                    bouquet++; // idhr hum jo bouquets tha hamre uske inc krdenge count bcz humne requeired number of adjacent flower milghye hai jisse hum apna bouquet form kr skhte hai 

                    flower = 0; // isko wps reset krenge kyuki ab humko aage ke flower ke liye check krna pdega manlo abhi humne start ke 3 din ke flower count krlegne toh ab hume 4 , 5 ,6 din kke flower count krke check pdega ki hamra bouquet ban skhta hai ki nhi
                  }
            }
            else{
                // Current flower hasn't bloomed, so the consecutive sequence breaks.
                // Reset the consecutive flower count.
                flower = 0;
            }
        }
        return bouquet>=m;  // simplee hai agr hume required amount of bouquet milgye jese hume 3 banne the agr hume utne bouquet form hogye toh return true hojyega yaha se 

    }
    int minDays(vector<int>& bloomday, int m, int k) {

        // Impossible case:
        // If the total flowers required (m * k) are more than the total flowers available,
        // then it's impossible to make the required bouquets even if we wait forever.
        //
        // Example:
        // bloomDay = [1, 2, 3, 4, 5]
        // m = 3, k = 2
        // Required flowers = 3 * 2 = 6
        // Avilable flowers = 5
        // => Impossible, so return -1.

        if ((long long)m * k > bloomday.size()){  //impossible case
            return -1;
        }


        int n = bloomday.size();
        int min1 =INT_MAX;
        int max1 = INT_MIN;
        for( int val : bloomday){
            min1 = min(min1, val);
            max1 = max(max1, val);
        }

        int start =min1;
        int end = max1;
        while( start<=end){
            int mid = start+ (end-start)/2;
            if(check(bloomday, m , k , mid)){
                end = mid-1; // less days par bhi possible hai aur flower khil rhe ho unhe dekhna check krnege
            }
            else{
                start = mid+1; // this will find that more days lagengee abhi flower khilne ko 
            }
        }

        return start;
        
    }
};