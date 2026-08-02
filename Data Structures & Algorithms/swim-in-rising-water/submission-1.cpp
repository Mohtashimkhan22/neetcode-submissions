class Solution {
public:
    int swimInWater(vector<vector<int>>& grid) {
        int n = grid.size();
        int m = grid[0].size();
    priority_queue<pair<int,pair<int,int>>,vector<pair<int,pair<int,int>>>,greater<pair<int,pair<int,int>>>> pq;
        pq.push({grid[0][0],{0,0}});
        vector<vector<int>> move = {{-1,0},{0,1},{1,0},{0,-1}};
        vector<vector<bool>> vis(n,vector<bool>(m,0));
        vis[0][0]=true;
        int ans = 9999;
        while(!pq.empty()){
            int c = pq.top().first;
            int j = pq.top().second.second;
            int i = pq.top().second.first;
            pq.pop();
            cout<<c<<" ";
            if(i==n-1 && j==m-1) ans = min(ans,c);
            for(auto it : move){
                int nr = i+it[0];
                int nc = j+it[1];
                int ct = c;
                if(nr>=0 && nc>=0 && nr<n && nc<m && !vis[nr][nc]){
                    if(grid[nr][nc]>ct) ct=grid[nr][nc];
                    pq.push({ct,{nr,nc}});
                    vis[nr][nc]=true;
                }
            }
        }
        return ans;
    }
};
