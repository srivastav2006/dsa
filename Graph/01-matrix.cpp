class Solution {
public:
    vector<vector<int>> updateMatrix(vector<vector<int>>& mat) {
        int n = mat.size(), m = mat[0].size();
        queue<pair<int,int>> q;

        // Push all 0s in the queue, set 1s to INT_MAX
        for(int i = 0; i < n; i++) {
            for(int j = 0; j < m; j++) {
                if(mat[i][j] == 0) {
                    q.push({i,j});
                } else {
                    mat[i][j] = INT_MAX;
                }
            }
        }

        vector<pair<int,int>> dirs = {{1,0},{-1,0},{0,1},{0,-1}};

        // BFS
        while(!q.empty()) {
            auto [x,y] = q.front(); q.pop();
            for(auto [dx,dy] : dirs) {
                int nx = x + dx, ny = y + dy;
                if(nx>=0 && nx<n && ny>=0 && ny<m) {
                    if(mat[nx][ny] > mat[x][y] + 1) {
                        mat[nx][ny] = mat[x][y] + 1;
                        q.push({nx,ny});
                    }
                }
            }
        }
        return mat;
    }
};
