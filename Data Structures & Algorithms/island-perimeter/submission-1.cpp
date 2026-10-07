class Solution {
public:
    int islandPerimeter(vector<vector<int>>& grid) {
        int n = grid.size();
        int m = grid[0].size();
        int count = 0;
        queue<vector<int>> q;
        vector<vector<bool>> vis(n,vector<bool>(m,false));
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                if(grid[i][j]==1){
                    count++;
                    q.push({i,j});
                    vis[i][j]=true;
                    break;
                }
            }
            if(count) break;
        }
        count = 0;
        vector<vector<int>> move = {{-1,0},{0,1},{1,0},{0,-1}};
        while(!q.empty()){
            auto itr = q.front();
            q.pop();
            for(auto it : move){
                int r = itr[0]+it[0];
                int c = itr[1]+it[1];
                if(r>=0 && c>=0 && r<n && c<m){
                    if(!vis[r][c] && grid[r][c]){
                        q.push({r,c});
                        vis[r][c]=true;
                    }
                    else if(grid[r][c]==0){
                        count++;
                    }
                }
                else count++;
            }
        }
        return count;
    }
};