class Solution {
    void dfs(vector<vector<char>>& grid,vector<vector<bool>>& vis,int r,int c){
        int n=grid.size(),m=grid[0].size();
        vis[r][c]=true;
        vector<vector<int>> move = {{-1,0},{0,1},{1,0},{0,-1}};
        for(auto it : move){
            int nr = r+it[0];
            int nc = c+it[1];
            if(nc>=0 && nr>=0 && nr<n && nc<m && !vis[nr][nc] && grid[nr][nc]=='1'){
                dfs(grid,vis,nr,nc);
            }
        }
    }
public:
    int numIslands(vector<vector<char>>& grid) {
        int n=grid.size(),m=grid[0].size();
        int count = 0;
        vector<vector<bool>> vis(n,vector<bool>(m,false));
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                if(!vis[i][j] && grid[i][j]=='1'){
                    count++;
                    dfs(grid,vis,i,j);
                }
            }
        }
        return count;
    }
};
