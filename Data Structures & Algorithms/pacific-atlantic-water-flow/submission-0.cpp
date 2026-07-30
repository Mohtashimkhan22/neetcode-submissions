class Solution {
    bool solver(vector<vector<int>>& heights,vector<vector<bool>> &vis,int i,int j,bool &pacific, bool &atlantic){
        int n = heights.size();
        int m = heights[0].size();
        if(i==n-1 || j==m-1)  atlantic=true;
        if(i==0 || j==0) pacific=true;
        if(pacific && atlantic) return true;
        vis[i][j]=true;
        vector<vector<int>> move = {{-1,0},{0,1},{1,0},{0,-1}};
        for(auto it : move){
            int nr = i + it[0];
            int nc = j + it[1];
            if(nr>=0 && nc>=0 && nr<n && nc<m && !vis[nr][nc] && heights[nr][nc]<=heights[i][j]){
                if(solver(heights,vis,nr,nc,pacific,atlantic)){
                    return true;
                }
            }
        }
        return false;
    }
public:
    vector<vector<int>> pacificAtlantic(vector<vector<int>>& heights) {
        vector<vector<int>> result;
        int n = heights.size();
        int m = heights[0].size();
        // result.push_back({0,m-1});
        // result.push_back({n-1,0});
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                vector<vector<bool>> vis(n,vector<bool>(m,false));
                bool atlantic = false;
                bool pacific = false;
                if(solver(heights,vis,i,j,pacific,atlantic)){
                    result.push_back({i,j});
                }
            }
        }
        return result;
    }
};
