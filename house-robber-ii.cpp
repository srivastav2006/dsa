class Solution {
public:
    int rob(vector<int>& a) {
        int n = a.size();

        if (n == 0) return 0;
        if (n == 1) return a[0];
        if (n == 2) return max(a[0], a[1]);

        vector<int> d(n - 1, 0);
        d[0] = a[0];
        d[1] = max(a[0], a[1]);
        for (int i = 2; i < n - 1; i++) {
            d[i] = max(d[i - 1], a[i] + d[i - 2]);
        }

        vector<int> e(n, 0);  
        e[1] = a[1];
        e[2] = max(a[1], a[2]);
        for (int i = 3; i < n; i++) {
            e[i] = max(e[i - 1], a[i] + e[i - 2]);
        }

        return max(d[n - 2], e[n - 1]);
    }
};
