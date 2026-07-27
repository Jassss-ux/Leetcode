class Solution {
public:
    int finalValueAfterOperations(vector<string>& operations) {
        int ans=0;
        for( string op : operations){
            if(op[1]=='+'){ // op string banake usko humne string ke 1 index ke sath comprare krliya hai pher agr 1 index pe + hua toh increment and agr decrement hua toh decremnet krdo and ans return krdo 
                ans++;
            }
            else{
                ans--;
            }
        }
        return ans;
        
        
    }
};