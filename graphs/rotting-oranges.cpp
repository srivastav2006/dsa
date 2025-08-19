class Solution {
public:
    int orangesRotting(vector<vector<int>>& grid) {
        int na = grid.size(), nb = grid[0].size();
        queue<pair<int,int>> qu;
        int fr = 0;

        for (int ia = 0; ia < na; ia++) {
            for (int jb = 0; jb < nb; jb++) {
                if (grid[ia][jb] == 2) qu.push({ia, jb});
                else if (grid[ia][jb] == 1) fr++;
            }
        }

        if (fr == 0) return 0;

        int mi = -1;
        int da[4] = {0,0,1,-1}, db[4] = {1,-1,0,0};

        while (!qu.empty()) {
            int sz = qu.size();
            mi++;
            while (sz--) {
                auto [ia, jb] = qu.front();
                qu.pop();
                for (int d = 0; d < 4; d++) {
                    int xa = ia + da[d], yb = jb + db[d];
                    if (xa >= 0 && xa < na && yb >= 0 && yb < nb && grid[xa][yb] == 1) {
                        grid[xa][yb] = 2;
                        fr--;
                        qu.push({xa, yb});
                    }
                }
            }
        }

        return fr == 0 ? mi : -1;
    }
};
