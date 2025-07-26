class Solution {
public:
    bool canPartition(vector<int>& a) {
        int n = a.size();
        int sum = 0;
        for (int i = 0; i < n; i++) {
            sum += a[i];
        }

        if (sum % 2 == 1) return false;

        int target = sum / 2;

        vector<vector<bool>> dp(n, vector<bool>(target + 1, false));

        
        if (a[0] <= target) dp[0][a[0]] = true;
        dp[0][0] = true;

        for (int i = 1; i < n; i++) {
            for (int j = 0; j <= target; j++) {
                bool nt = dp[i - 1][j];
                bool t = false;
                if (j >= a[i]) t = dp[i - 1][j - a[i]];
                dp[i][j] = t || nt;
            }
        }

        return dp[n - 1][target];
    }
};
