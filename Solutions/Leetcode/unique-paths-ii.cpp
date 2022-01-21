class Solution {
public:
    int m, n;

    int uniquePathsWithObstacles(vector<vector<int>>& grid) {

        n = grid.size();
        m = grid[0].size();
        if (grid[n - 1][m - 1] == 1)
        {
            return 0;
        }

        long long dp[n][m];
        memset(dp, 0, sizeof dp);

        for (int row = n - 1; row >= 0; row--)
        {
            if (grid[row][m - 1] == 1)
                break;
            dp[row][m - 1] = 1;
        }
        for (int col = m - 1; col >= 0; col--)
        {
            if (grid[n - 1][col] == 1)
                break;
            dp[n - 1][col] = 1;
        }
        for (int row = n - 2; row >= 0; row--)
        {
            for (int col = m - 2; col >= 0; col--)
            {
                long long frombottom = 0;
                if (grid[row + 1][col] == 0)
                    frombottom = dp[row + 1][col];

                long long fromright = 0;
                if (grid[row][col + 1] == 0)
                    fromright = dp[row][col + 1];

                if (grid[row][col] == 0)
                    dp[row][col] = frombottom + fromright ;
            }
        }
        for (int i = 0; i < n; i++)
        {
            for (int j = 0; j < m; j++)
            {
                cout << dp[i][j] << " ";
            }
            cout << endl;
        }
        return dp[0][0];
    }
};