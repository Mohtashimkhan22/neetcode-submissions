class Solution {
public:
    int orangesRotting(vector<vector<int>>& grid) {
        queue<pair<pair<int,int>,int>> q;
        int n=grid.size(),m=grid[0].size();
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                if(grid[i][j]==2){
                    q.push({{i,j},0});
                }
            }
        }
        vector<vector<int>> move = {{-1,0},{0,1},{1,0},{0,-1}};           
        vector<vector<int>> dist(n,vector<int>(m,9999));
        int maxi = 0;
        while(!q.empty()){
            int r = q.front().first.first;
            int c = q.front().first.second;
            int ct = q.front().second;
            q.pop();
            maxi=max(maxi,ct);
            for(auto it : move){
                int nr = r+it[0];
                int nc = c+it[1];
                if(nc>=0 && nr>=0 && nr<n && nc<m && dist[nr][nc]>ct && grid[nr][nc]==1){
                    q.push({{nr,nc},ct+1});
                    dist[nr][nc]=ct+1;
                }
            }
        }
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                if(dist[i][j]==9999 && grid[i][j]==1){
                    return -1;
                }
            }
        }
        return maxi;
    }
};
