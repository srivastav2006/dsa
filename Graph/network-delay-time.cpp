class Solution {
public:
    int networkDelayTime(vector<vector<int>>& times, int n, int k) {
        vector<vector<pair<int,int>>> adj(n+1);
        for (auto &e : times) {
            adj[e[0]].push_back({e[1], e[2]});
        }

        const int INF = 1e9;
        vector<int> dist(n+1, INF);
        dist[k] = 0;

        priority_queue<pair<int,int>, vector<pair<int,int>>, greater<>> pq;
        pq.push({0, k}); // {time, node}

        while (!pq.empty()) {
            auto [time, u] = pq.top();
            pq.pop();

            if (time > dist[u]) continue;

            for (auto &[v, w] : adj[u]) {
                if (time + w < dist[v]) {
                    dist[v] = time + w;
                    pq.push({dist[v], v});
                }
            }
        }

        int ans = *max_element(dist.begin()+1, dist.end());
        return ans == INF ? -1 : ans;
    }
};
