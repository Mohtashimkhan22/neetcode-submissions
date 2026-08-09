class DSU{
    vector<int> parent;
public:
    DSU(int n){
        parent.resize(n);
        for(int i=0;i<n;i++){
            parent[i]=i;
        }
    }
    int find(int u){
        if(parent[u]!=u) parent[u]=find(parent[u]);
        return parent[u];
    }
    void union_parent(int u,int v){
        parent[u]=v;
    }
};
class Solution {
public:
    int minCostConnectPoints(vector<vector<int>>& points) {
        priority_queue<pair<int,vector<int>>,vector<pair<int,vector<int>>>,greater<pair<int,vector<int>>>> pq;
        int n = points.size();
        for(int i=0;i<n-1;i++){
            for(int j=i+1;j<n;j++){
                int x1 = points[i][0];
                int y1 = points[i][1];
                int x2 = points[j][0];
                int y2 = points[j][1];
                int dist = abs(x1-x2)+abs(y1-y2);
                pq.push({dist,{i,j}});
            }
        }
        DSU dsu(n);

        int edges=0;
        int cost = 0;
        while(!pq.empty() && edges<n-1){
            
            int u = pq.top().second[0];
            int v = pq.top().second[1];
            int pu = dsu.find(u);
            int pv = dsu.find(v);
            if(pu!=pv){
                cost+=pq.top().first;
                edges++;
                dsu.union_parent(pu,pv);
            }
            
            pq.pop();

        }
        return cost;
    }
};
