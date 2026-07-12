class Solution {
public:
    int maxCoins(vector<int>& piles) {
        sort(piles.begin(), piles.end());

        int n = piles.size();
        int left = 0;
        int right = n - 1;
        int sum = 0;

        while (left < right) {
            right--;               // Alice takes the largest
            sum += piles[right];   // You take the second largest
            right--;
            left++;                // Bob takes the smallest
        }

        return sum;
    }
};