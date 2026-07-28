class Solution {
public:
    int maxProduct(int n) {
        // jo bhi hamra n hai uski humko max and second max reaminder find krna pdega and unhe mulltiple krenge hum
        int max1 = 0;
        int max2 = 0;
        while(n>0){
            int remainder =  n%10;
            if( remainder >= max1){
                max2 = max1;
                max1= remainder;
            }
            else if( remainder > max2){
                max2 = remainder;
            }
            
            n = n/10;
        }
        return max1 * max2;
        
    }
};