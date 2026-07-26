class Solution {
public:
    bool canWinNim(int n) {
        //logic bas yeh 4 ke multiple pe player 1 harta hai baki sab mein jeet jata hai 
        if(n%4==0){
            return false;
        }
        else{
            return true;
        }
    }
};