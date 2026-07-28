class Solution {
    int dfs(vector<vector<int>>& grid,vector<vector<bool>>& vis,int r,int c){
        int n=grid.size(),m=grid[0].size();
        vis[r][c]=true;
        int area = 1;
        vector<vector<int>> move = {{-1,0},{0,1},{1,0},{0,-1}};
        for(auto it : move){
            int nr = r+it[0];
            int nc = c+it[1];
            if(nc>=0 && nr>=0 && nr<n && nc<m && !vis[nr][nc] && grid[nr][nc]==1){
                area+=dfs(grid,vis,nr,nc);
            }
        }
        return area;
    }
public:
    int maxAreaOfIsland(vector<vector<int>>& grid) {
        int n=grid.size(),m=grid[0].size();
        int maxArea = 0;
        vector<vector<bool>> vis(n,vector<bool>(m,false));
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                if(!vis[i][j] && grid[i][j]==1){
                    maxArea=max(dfs(grid,vis,i,j),maxArea);
                }
            }
        }
        return maxArea;
    }
};
