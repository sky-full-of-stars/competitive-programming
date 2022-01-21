class Solution {
public:
    int dp[101][101];
    int n;
    int INF =  1000;

    void init(int n, vector<vector<int>>& matrix)
    {
        for (int i = 0; i < n; i++)
            dp[n - 1][i] = matrix[n - 1][i];
    }
    void doCalc(vector<vector<int>>& matrix)
    {
        for (int row = n - 2; row >= 0; row--)
        {
            for (int col = 0; col < n; col++)
            {
                int bottom = dp[row + 1][col];

                int bottomLeft = INF;
                if (col != 0)
                    bottomLeft = dp[row + 1][col - 1];

                int bottomRight = INF;
                if (col != n - 1)
                    bottomRight = dp[row + 1][col + 1];

                int minimum = min(bottom, min(bottomLeft, bottomRight));
                dp[row][col] = matrix[row][col] + minimum;
            }
        }
    }
    void debug()
    {
        for (int row = 0; row < n; row++)
        {
            for (int col = 0; col < n; col++)
            {
                cerr << dp[row][col] << " ";
            }
            cerr << endl;
        }
    }
    int getRes()
    {
        int ans = INF;
        for (int col = 0; col < n; col++)
            ans = min(ans, dp[0][col]);
        return ans;
    }
    int minFallingPathSum(vector<vector<int>>& matrix) {
        n = matrix.size();
        init(n, matrix);;
        doCalc(matrix);
        //debug();
        return getRes();
    }
};