class Solution {
public:
    int maxProfit(int c, vector<int>& a) {
        int n = a.size();
        vector<vector<vector<int>>> dp(n + 1, vector<vector<int>>(2, vector<int>(c + 1, 0)));

        for (int k = 0; k <= c; ++k) {
            dp[1][0][k] = 0;
            dp[1][1][k] = -a[0];
        }

        for (int i = 2; i <= n; ++i) {
            for (int k = 0; k <= c; ++k) {
                // Not holding
                dp[i][0][k] = dp[i - 1][0][k];
                if (k > 0 && dp[i - 1][1][k] != INT_MIN)
                    dp[i][0][k] = max(dp[i][0][k], dp[i - 1][1][k] + a[i - 1]);

                // Holding
                dp[i][1][k] = dp[i - 1][1][k];
                if (k > 0 && dp[i - 1][0][k - 1] != INT_MIN)
                    dp[i][1][k] = max(dp[i][1][k], dp[i - 1][0][k - 1] - a[i - 1]);
            }
        }

        int ans = 0;
        for (int k = 0; k <= c; ++k) {
            ans = max(ans, dp[n][0][k]);
        }
        return ans;
    }
};
