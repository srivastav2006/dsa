class Solution {
public:
    int minimumEffortPath(vector<vector<int>>& heights) {
        int n = heights.size(), m = heights[0].size();
        vector<vector<int>> dist(n, vector<int>(m, INT_MAX));
        dist[0][0] = 0;

        priority_queue<tuple<int,int,int>, vector<tuple<int,int,int>>, greater<>> pq;
        pq.push({0, 0, 0}); // {effort, row, col}

        vector<int> dr = {0, 1, 0, -1};
        vector<int> dc = {1, 0, -1, 0};

        while(!pq.empty()) {
            auto [effort, r, c] = pq.top(); pq.pop();
            if(r == n-1 && c == m-1) return effort;
            if(effort > dist[r][c]) continue;

            for(int k=0;k<4;k++) {
                int nr = r + dr[k], nc = c + dc[k];
                if(nr>=0 && nr<n && nc>=0 && nc<m) {
                    int newEffort = max(effort, abs(heights[r][c] - heights[nr][nc]));
                    if(newEffort < dist[nr][nc]) {
                        dist[nr][nc] = newEffort;
                        pq.push({newEffort, nr, nc});
                    }
                }
            }
        }
        return 0;
    }
};
