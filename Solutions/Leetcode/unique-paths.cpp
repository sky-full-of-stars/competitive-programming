class Solution {
public:
    int uniquePaths(int m, int n) {
        int dp[n][m];
        for (int i = 0; i < n; i++)
            dp[i][m - 1] = 1;
        for (int i = 0; i < m; i++)
            dp[n - 1][i] = 1;

        for (int row = n - 2; row >= 0; row--)
        {
            for (int col = m - 2; col >= 0; col--)
            {
                dp[row][col] = dp[row + 1][col] + dp[row][col + 1];
            }
        }
        return dp[0][0];
    }
};