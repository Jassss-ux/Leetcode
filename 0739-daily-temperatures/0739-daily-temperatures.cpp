class Solution {
public:
    vector<int> dailyTemperatures(vector<int>& temp) {
        stack<int>s;
        int n =temp.size();
        vector<int>ans(n,0);
        
        for( int  i =n-1; i>=0;i--){
            while( s.size()>0 && temp[s.top()]<=temp[i]){ // and idhr hum temp[s.top()]  this will give the index of the top elleent of the stack
                s.pop();
            }
            if(s.empty()){
                ans[i] = 0;
            }
            else{
                ans[i]= s.top() - i;   //diffrence of indexes hamra no of days ke equal hai 

            }
            s.push(i); //index add krna pdeega stack mein kyuki humne index minus krke value mlegi no of days ki naki value 73  -74 aese krke nhi milegge index minus hoga ex 0-1 = 1 nno of days difffrence
        }
        return ans;
    }
};