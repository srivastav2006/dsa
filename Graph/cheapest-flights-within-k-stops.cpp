class Solution {
public:
    int findCheapestPrice(int n, vector<vector<int>>& flights, int src, int dst, int k) {


        vector< pair<int,int> > adj[n];
        for(auto f:flights){
            int u=f[0],v=f[1],w=f[2];
            adj[u].push_back({v,w});
        }

        
        queue<tuple<int,int,int>> q;
        //{stops,node,cost}
        q.push({0,src,0});

        vector<int> dist(n,INT_MAX);
        dist[src] = 0;

        while(!q.empty()){
            auto [stops,node,cost] = q.front();
            q.pop();

            if(stops > k) continue;

            
            for(auto it: adj[node]){
                int price = it.second;
                int adjNode = it.first;
                int new_price = price + cost;
            
                if(new_price < dist[adjNode] &&  stops<=k){
                    dist[adjNode] = new_price;
                    q.push({stops+1,adjNode,new_price});

                }
            }
        }

        if(dist[dst]==INT_MAX){
            return -1;
        }
        return dist[dst];
        
    }
};