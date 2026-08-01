class Solution {
public:
    int networkDelayTime(vector<vector<int>>& times, int n, int k) {
        vector<vector<pair<int,int>>> adj(n+1);
        for(auto it : times){
            adj[it[0]].push_back({it[1],it[2]});
        }
        // vector<bool> vis(n+1,false);
        vector<int> costs(n+1,INT_MAX);
        priority_queue<pair<int,int>> pq;
        pq.push({k,0});
        // vis[k]=true;
        costs[k]=0;
        while(!pq.empty()){
            int node = pq.top().first;
            int cost = pq.top().second;
            pq.pop();
            for(auto it : adj[node]){
                int total = cost+it.second;
                if(total<costs[it.first]){
                    costs[it.first]=total;
                    pq.push({it.first,costs[it.first]});
                }
            }
        }
        int maxi=0;
        for(int i=1;i<=n;i++){
            maxi=max(maxi,costs[i]);
        }
        return maxi==INT_MAX?-1:maxi;
    }
};
