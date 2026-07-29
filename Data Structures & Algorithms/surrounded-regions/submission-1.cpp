class Solution {
public:
    void solve(vector<vector<char>>& board) {
        queue<pair<int,int>> q;
        int n=board.size(),m=board[0].size();
        vector<vector<bool>> vis(n,vector<bool>(m,false));

        for(int j=0;j<m;j++){
            if(board[0][j]=='O'){
                q.push({0,j});
                vis[0][j]=true;
            }
            if(board[n-1][j]=='O'){
                q.push({n-1,j});
                vis[n-1][j]=true;
            }
        }
        for(int j=0;j<n;j++){
            if(board[j][0]=='O'){
                q.push({j,0});
                vis[j][0]=true;
            }
            if(board[j][m-1]=='O'){
                q.push({j,m-1});
                vis[j][m-1]=true;
            }
        }
        vector<vector<int>> move = {{-1,0},{0,1},{1,0},{0,-1}};           
        
        int maxi = 0;
        while(!q.empty()){
            int r = q.front().first;
            int c = q.front().second;
            q.pop();
            for(auto it : move){
                int nr = r+it[0];
                int nc = c+it[1];
                if(nc>=0 && nr>=0 && nr<n && nc<m && !vis[nr][nc] && board[nr][nc]=='O'){
                    q.push({nr,nc});
                    vis[nr][nc]=true;
                }
            }
        }
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                if(!vis[i][j] && board[i][j]=='O'){
                    board[i][j]='X';
                }
            }
        }
        return;
    }
};
