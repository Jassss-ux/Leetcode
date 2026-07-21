class Solution {
public:
    int matchPlayersAndTrainers(vector<int>& players, vector<int>& trainers) {
        sort(players.begin(), players.end());
        sort(trainers.begin(),trainers.end());//sort islye krha jisse value sequence wise sahi se compare hoajye mix up na ho 
        int n = players.size();
        int m = trainers.size();
        int count =0;
        int i = 0;
        int j = 0;
        while(i<n && j<m){
            if(players[i]<=trainers[j]){
                count++;
                i++;
                j++;
            }
            else{
                j++;  // ex players =  9 and tranier = 8 , 6 
                // toh jab 9<=8 chala tab false hoga then humne pher next trainer that is 6 ke sath compare krna pdega 9 ko isslye j++
            }
        }
        return count;
        
    }
};