class Solution {
public:
    void dfs(int na, vector<vector<int>>& gr, vector<int>& vs) {
        vs[na] = 1;
        for (int nb = 0; nb < gr.size(); nb++) {
            if (gr[na][nb] == 1 && !vs[nb]) {
                dfs(nb, gr, vs);
            }
        }
    }

    int findCircleNum(vector<vector<int>>& isConnected) {
        int na = isConnected.size();
        vector<int> vs(na, 0);
        int ct = 0;

        for (int i = 0; i < na; i++) {
            if (!vs[i]) {
                ct++;
                dfs(i, isConnected, vs);
            }
        }
        return ct;
    }
};
