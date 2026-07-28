class Solution {
    int infNum = 2147483647;
public:
    void islandsAndTreasure(vector<vector<int>>& grid) {
        vector<pair<int,int>> lands;
        int n=grid.size(),m=grid[0].size();
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                if(grid[i][j]==infNum){
                    lands.push_back({i,j});
                }
            }
        }
        vector<vector<int>> move = {{-1,0},{0,1},{1,0},{0,-1}};
        for(auto itr : lands){
            int i = itr.first;
            int j = itr.second;
            queue<pair<pair<int,int>,int>> q;
            q.push({{i,j},0});
            vector<vector<bool>> vis(n,vector<bool>(m,false));
            vis[i][j]=true;
            while(!q.empty()){
                int r = q.front().first.first;
                int c = q.front().first.second;
                int ct = q.front().second;
                q.pop();
                if(grid[r][c]==0){
                    grid[i][j]=ct;
                    break;
                }
                for(auto it : move){
                    int nr = r+it[0];
                    int nc = c+it[1];
                    if(nc>=0 && nr>=0 && nr<n && nc<m && !vis[nr][nc] && grid[nr][nc]!=-1){
                        q.push({{nr,nc},ct+1});
                        vis[nr][nc]=true;
                    }
                }
            }
        }
    }
};
