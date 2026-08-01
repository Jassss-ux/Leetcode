class Solution {
public:
    vector<int> finalPrices(vector<int>& prices) {
        // int n = prices.size();//brute force tareeka solve krna ka 
        // // jab STACK PADHLEGA TAB ISKA OPTIMAL SOLUTION SAMJ AYEAGA JO STACK USE KRKE HOTA HAI 
        // for( int i =0;i<n;i++){
        //     for( int j =i+1;j<n;j++){
        //         if( prices[j]<=prices[i]){
        //             prices[i]=prices[i]-prices[j];
        //             break;
        //         }
        //     }

        // }
        // return prices;

        //optimal solution is based on next smaller number concept lag rha h 
        vector<int>ans(prices.size());
        stack<int>s;
        int n = prices.size();
        for( int i = n-1 ; i>=0;i--){
            while( s.size() > 0 && s.top() >  prices[i]){
                s.pop();
            }

            if(s.empty()){
                ans[i] = prices[i];
            }

            else{
                ans[i]  = prices[i] - s.top();
            } 

            s.push(prices[i]);
        }

        return ans;


        
    }
};