class Solution {
public:
    int totalMoney(int n) {
        int monday = 1; 
        int sum = 0;
        while(n>0){
            int money = monday;
            for(int i = 0 ; i<7 && n>0 ;i++){
                sum = sum+money;
                money++;
                n--;  //n  =  10 mana toh pher iterate krega 9 pher  8   pher 7 aese jake sare days calculate hojyenge 
                
            }
            monday++; //bcz monday ko dollar mein +1 hoga har week mein 
        }
        return sum;
    }
};