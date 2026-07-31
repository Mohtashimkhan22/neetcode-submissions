class Solution {
    vector<int> parent;
    void fillParent(int n){
        parent.resize(n+1);
        for(int i=0;i<=n;i++) parent[i]=i;
    }
    int findParent(int node){
        if(parent[node]!=node) parent[node] = findParent(parent[node]);
        return parent[node];
    }

public:
    vector<int> findRedundantConnection(vector<vector<int>>& edges) {
        int n = edges.size();
        fillParent(n);
        vector<vector<int>> adj(n+1);

        for(auto it : edges){
            int pu = findParent(it[0]);
            int pv = findParent(it[1]);
            // cout<<pu<<" "<<pv<<endl;
            if(pu!=pv){
                parent[pu]=pv;
            }
            else return it;
        }

        return {};
    }
};
