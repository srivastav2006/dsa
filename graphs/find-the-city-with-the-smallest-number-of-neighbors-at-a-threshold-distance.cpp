class Solution {
public:
    int findTheCity(int n, vector<vector<int>>& edges, int distanceThreshold) {
        const int INF = 1e9;
        vector<vector<int>> dist(n, vector<int>(n, INF));
        
        // distance to itself = 0
        for (int i = 0; i < n; i++) 
            dist[i][i] = 0;
        
        // initialize edge distances
        for (auto &e : edges) {
            int u = e[0], v = e[1], w = e[2];
            dist[u][v] = min(dist[u][v], w);
            dist[v][u] = min(dist[v][u], w);
        }
        
        // Floyd-Warshall
        for (int k = 0; k < n; k++) {
            for (int i = 0; i < n; i++) {
                for (int j = 0; j < n; j++) {
                    if (dist[i][k] + dist[k][j] < dist[i][j]) {
                        dist[i][j] = dist[i][k] + dist[k][j];
                    }
                }
            }
        }
        
        // find city with minimum reachable count
        int res = -1, minReachable = n;
        for (int i = 0; i < n; i++) {
            int cnt = 0;
            for (int j = 0; j < n; j++) {
                if (i != j && dist[i][j] <= distanceThreshold)
                    cnt++;
            }
            // pick city with fewer neighbors, break ties with larger index
            if (cnt <= minReachable) {
                minReachable = cnt;
                res = i;
            }
        }
        
        return res;
    }
};
