class Solution {
public:
    int n, m;
    int dp[201][201];

    void init(int n, int m, vector<vector<int>>& grid)
    {
        dp[n - 1][m - 1] = grid[n - 1][m - 1];

        for (int col = m - 2; col >= 0; col--)
            dp[n - 1][col] = grid[n - 1][col] + dp[n - 1][col + 1];

        for (int row = n - 2; row >= 0; row--)
            dp[row][m - 1] = grid[row][m - 1] + dp[row + 1][m - 1];
    }

    void doCalc(vector<vector<int>>& grid)
    {
        for (int row = n - 2; row >= 0; row--)
        {
            for (int col = m - 2; col >= 0; col--)
            {
                dp[row][col] = grid[row][col] + min(dp[row + 1][col], dp[row][col + 1]);
            }
        }
    }

    void debug()
    {
        for (int i = 0; i < n; i++)
        {
            for (int j = 0; j < m; j++)
            {
                cerr << dp[i][j] << " ";
            }
            cerr << endl;
        }
    }

    int minPathSum(vector<vector<int>>& grid) {
        n = grid.size();
        m = grid[0].size();
        init(n, m, grid);
        doCalc(grid);
        //debug();
        return dp[0][0];
    }

};