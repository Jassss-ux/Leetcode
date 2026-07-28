class Solution {
public:
    vector<vector<int>> generateMatrix(int n) {
        vector<vector<int>> ans(n, vector<int>(n));

        int left = 0, right = n - 1;
        int top = 0, bottom = n - 1;
        int num =1;

        while (left <= right && top <= bottom) {

            // Top row
            for (int i = left; i <= right; i++) {
                ans[top][i]=num++;
            }
            top++;

            // Right column
            for (int i = top; i <= bottom; i++) {
                ans[i][right] = num++;
            }
            right--;

            // Bottom row
            if (top <= bottom) {
                for (int i = right; i >= left; i--) {
                    ans[bottom][i] = num++;
                }
                bottom--;
            }

            // Left column
            if (left <= right) {
                for (int i = bottom; i >= top; i--) {
                    ans[i][left] = num++;
                }
                left++;
            }
        }

        return ans;
    }
        
};