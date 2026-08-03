class Solution {
public:
    int findCheapestPrice(int n, vector<vector<int>>& flights, int src, int dst, int k) {
        vector<vector<pair<int,int>>> adj(n);
        for(auto it : flights){
            adj[it[0]].push_back({it[1],it[2]});
        }
        vector<int> dist(n,INT_MAX);
        queue<pair<int,pair<int,int>>> pq;
        pq.push({0,{src,0}});
        dist[src]=0;
        while(!pq.empty()){
            int cost = pq.front().first;
            int node = pq.front().second.first;
            int step = pq.front().second.second;
            pq.pop();
            cout<<node<<" "<<cost<<endl;
            if(step==k+1) continue;

            for(auto it : adj[node]){
                if(dist[it.first]>cost+it.second){
                    pq.push({cost+it.second,{it.first,step+1}});
                    dist[it.first]=cost+it.second;
                }
            }
        }
        // for(auto it : dist) cout<<it<<" ";
        return dist[dst]==INT_MAX?-1:dist[dst];
    }
};
// ,vector<pair<int,pair<int,int>>>,greater<pair<int,pair<int,int>>>