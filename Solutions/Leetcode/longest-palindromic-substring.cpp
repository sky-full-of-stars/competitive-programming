class Solution {
public:
    string longestPalindrome(string s) {

        int n = s.length();
        if (n == 0 or n == 1)
            return s;

        int dp[n + 1][n + 1];
        memset(dp, 0, sizeof(dp));

        for (int i = 0; i <= n; i++) //i=subsetLen
            dp[1][i] = dp[0][i] = 1;

        int len = 1, end = 0;
        for (int subsetLen = 2; subsetLen <= n; subsetLen++)
        {
            for (int endIdx = subsetLen; endIdx <= n; endIdx++) //1 indexed string
            {
                if ((s[endIdx - 1] == s[endIdx - subsetLen]) and (dp[subsetLen - 2][endIdx - 1]))
                {
                    dp[subsetLen][endIdx] = 1; len = subsetLen, end = endIdx - 1;
                }
                else
                {
                    dp[subsetLen][endIdx] = 0;
                }
            }
        }
        // for(int i=0;i<=n;i++) {
        //     for(int j=0;j<=n;j++) {
        //         cout<<dp[i][j]<<" ";
        //     }
        //     cout<<endl;
        // }

        string res = "";
        if (len == 1)
        {
            //cout<<"len:"<<len<<" "<<"end: "<<end<<endl;
            res.push_back(s[end]);
        }
        else
        {
            //cout<<"len:"<<len<<" "<<"end: "<<end<<endl;
            for (int idx = end - len + 1; idx <= end; idx++)
                res.push_back(s[idx]);
        }
        return res;

    }
};