class Solution {
public:
    int maxScore(vector<int>& card, int k) {
        int n = card.size(); //this will contain the size of the array card
        int leftsum =0;
        int rightsum =0;
        int maxsum =0;
        
        // step 1 take the sum of first four element of the array which start from 0 and goes upto K bcz that is the max length of element that we can take
        for( int i =0 ; i<k ;i++){
            leftsum = leftsum + card[i];

            maxsum = leftsum; //at the start maxsum will be equal to the sum of first 4 element so maxsum = lsum
        }

        // step 2 when we remove the element from the left sum then we have to add an element from the back suppose we remove k-1 element from the leftsum the we have to add n-1 element from the back ex2: we remove k-2 element and then we have to add n-2 element 

        //For adding the n-1,n-2 element we take a rightidx that start from N-1 so we can add it
        int rightidx =n-1;

        //we start a loop from K-1 position so that we can remove k-1 number and move backward in that
        for(int i=k-1;i>=0;i--){
            leftsum = leftsum - card[i];  //minus K-1 element
            rightsum =  rightsum + card[rightidx]; //adding N-1 element
            rightidx--; //bcz we have to travel backward n-1 then n-2 then n-3and so on islye rightidx-- hoga

            maxsum = max(maxsum, (leftsum+rightsum));
        }
        return maxsum;

    }
};