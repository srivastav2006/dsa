class Solution {
public:
    int minPathSum(vector<vector<int>>& a) {
        int n = a.size();
        int m = a[0].size();
        vector<vector<int>> dp(n, vector<int>(m, 0));

        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                if (i == 0 && j == 0) {
                    dp[i][j] = a[i][j];
                } else {
                    int up = a[i][j];
                    if (i > 0) up += dp[i-1][j];
                    else up = 1e9;

                    int left = a[i][j];
                    if (j > 0) left += dp[i][j-1];
                    else left = 1e9;

                    dp[i][j] = min(up, left);
                }
            }
        }
        return dp[n-1][m-1];
    }
};
