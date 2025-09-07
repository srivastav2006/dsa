class Solution {
public:
    void dfs(vector<vector<int>>& grid, int i, int j) {
        int n = grid.size(), m = grid[0].size();
        if(i < 0 || j < 0 || i >= n || j >= m || grid[i][j] == 0) return;

        grid[i][j] = 0; // mark visited (turn land into sea)

        dfs(grid, i+1, j);
        dfs(grid, i-1, j);
        dfs(grid, i, j+1);
        dfs(grid, i, j-1);
    }

    int numEnclaves(vector<vector<int>>& grid) {
        int n = grid.size(), m = grid[0].size();

        // Step 1: eliminate land connected to border
        for(int j = 0; j < m; j++) {
            if(grid[0][j] == 1) dfs(grid, 0, j);
            if(grid[n-1][j] == 1) dfs(grid, n-1, j);
        }
        for(int i = 0; i < n; i++) {
            if(grid[i][0] == 1) dfs(grid, i, 0);
            if(grid[i][m-1] == 1) dfs(grid, i, m-1);
        }

        // Step 2: count remaining land
        int cnt = 0;
        for(int i = 0; i < n; i++) {
            for(int j = 0; j < m; j++) {
                if(grid[i][j] == 1) cnt++;
            }
        }
        return cnt;
    }
};
