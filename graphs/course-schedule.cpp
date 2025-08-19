class Solution {
public:
    bool canFinish(int numCourses, vector<vector<int>>& prerequisites) {
        vector<vector<int>> adj(numCourses);
        vector<int> indeg(numCourses, 0);

        for (auto &p : prerequisites) {
            adj[p[1]].push_back(p[0]);
            indeg[p[0]]++;
        }

        queue<int> qu;
        for (int i = 0; i < numCourses; i++) {
            if (indeg[i] == 0) qu.push(i);
        }

        int cnt = 0;
        while (!qu.empty()) {
            int cr = qu.front();
            qu.pop();
            cnt++;
            for (int nx : adj[cr]) {
                indeg[nx]--;
                if (indeg[nx] == 0) qu.push(nx);
            }
        }

        return cnt == numCourses;
    }
};
