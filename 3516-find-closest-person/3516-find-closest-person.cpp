class Solution {
public:
    int findClosest(int x, int y, int z) {
        int distance  = abs(x-z);
        int distance1 = abs(y-z);
        if( distance == distance1){
            return 0;
        }
        if( distance< distance1){
            return 1;
        }
        return 2;
        
    }
};