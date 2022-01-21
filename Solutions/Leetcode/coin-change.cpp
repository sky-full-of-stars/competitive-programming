class Solution {
public:
    int coinChange(vector<int>& coins, int amount) {
        int INF = 1e7 + 7;

        int minCoinsNeeded[amount + 1];
        for (int i = 0; i <= amount; i++) minCoinsNeeded[i] = INF;
        minCoinsNeeded[0] = 0;

        for (int sumToMake = 1; sumToMake <= amount; sumToMake++)
        {
            int ans = INF;
            for (int denomination : coins)
            {
                if (denomination <= sumToMake)
                {
                    ans = min(ans, minCoinsNeeded[sumToMake - denomination]);
                }
            }
            minCoinsNeeded[sumToMake] = (ans != INF) ? ans + 1 : INF;
        }

        return (minCoinsNeeded[amount] == INF) ? (-1) : (minCoinsNeeded[amount]);

    }
};