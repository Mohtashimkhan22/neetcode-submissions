class Solution {
public:
    bool validTree(int n, vector<vector<int>>& edges) {
        vector<vector<int>> adj(n);
        vector<bool> vis(n,false);
        if(edges.size()<n-1) return false;

        for(auto it : edges){
            adj[it[0]].push_back(it[1]);
            adj[it[1]].push_back(it[0]);
        }
        queue<pair<int,int>> q;
        q.push({0,-1});
        int visited=0;
        vis[0]=true;
        while(!q.empty()){
            auto [node,parent] = q.front();
            q.pop();
            visited++;
            for(auto it : adj[node]){
                if(!vis[it]){
                    q.push({it,node});
                    vis[it]=true;
                }
                else if(parent!=it) return false;
            }
        }

        return visited==n;
    }
};
