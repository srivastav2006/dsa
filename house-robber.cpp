class Solution {
public:
    int rob(vector<int>& a) {
        int n = a.size();
        if (n == 0) return 0;
        if (n == 1) return a[0];

        int prev2 = a[0];
        int prev1 = max(a[0], a[1]);

        for (int i = 2; i < n; i++) {
            int curr = max(prev1, a[i] + prev2);
            prev2 = prev1;
            prev1 = curr;
        }

        return prev1;
    }
};
