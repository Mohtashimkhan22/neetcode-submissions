class Solution {
    int solver(int i,int j,vector<vector<int>> &dp,vector<vector<int>>& matrix){
        int n = matrix.size();
        int m = matrix[0].size();
        vector<vector<int>> move={{-1,0},{0,1},{1,0},{0,-1}};
        if(dp[i][j]!=-1) return dp[i][j];
        int maxi = 0;
        for(auto it : move){
            int r = i+it[0];
            int c = j+it[1];
            if(r>=0 && c>=0 && r<n && c<m && matrix[r][c]>matrix[i][j]){
                maxi = max(maxi,1+solver(r,c,dp,matrix));
            }
        }
        return dp[i][j]=maxi;
    }
public:
    int longestIncreasingPath(vector<vector<int>>& matrix) {
        int n = matrix.size();
        int m = matrix[0].size();
        int maxi = 0;
        vector<vector<int>> dp(n,vector<int>(m,-1));
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                int ans =solver(i,j,dp,matrix);
                maxi=max(maxi,ans);
            }
        }
        return maxi+1;
    }
};
