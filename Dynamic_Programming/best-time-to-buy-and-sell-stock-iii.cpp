class Solution {
public:
    int maxProfit(vector<int>& a) {
        int n = a.size();
        // dp[i][j][k] means:
        // Day i, holding state j (0 = not holding, 1 = holding), remaining transactions k
        vector<vector<vector<int>>> dp(n + 1, vector<vector<int>>(2, vector<int>(3, 0)));

        // Initialization:
        // On day 0, you can't have any stock, and profit is 0
        for (int k = 0; k < 3; ++k) {
            dp[0][0][k] = 0;
            dp[0][1][k] = INT_MIN; // impossible to hold stock before day 1
        }

        for (int i = 1; i <= n; ++i) {
            for (int k = 0; k < 3; ++k) {
                // Not holding
                dp[i][0][k] = dp[i - 1][0][k]; // do nothing
                if (k > 0 && dp[i - 1][1][k] != INT_MIN) {
                    dp[i][0][k] = max(dp[i][0][k], dp[i - 1][1][k] + a[i - 1]); // sell
                }

                // Holding
                dp[i][1][k] = dp[i - 1][1][k]; // do nothing
                if (k > 0 && dp[i - 1][0][k - 1] != INT_MIN) {
                    dp[i][1][k] = max(dp[i][1][k], dp[i - 1][0][k - 1] - a[i - 1]); // buy
                }
            }
        }

        // Answer is the max profit on day n, with no stock in hand
        return max({dp[n][0][0], dp[n][0][1], dp[n][0][2]});
    }
};
