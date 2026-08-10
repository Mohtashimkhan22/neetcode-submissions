class Solution {
    int solver(int m,int n,vector<vector<int>> &dp,int i,int j){
        if(i==m-1 && j==n-1) return 1;
        if(i>=m || j>=n) return 0;
        if(dp[i][j]!=-1) return dp[i][j];
        
        dp[i][j]=solver(m,n,dp,i+1,j)+solver(m,n,dp,i,j+1);
        return dp[i][j];
    }
public:
    int uniquePaths(int m, int n) {
        vector<vector<int>> dp(m,vector<int>(n,-1));
        return solver(m,n,dp,0,0);
    }
};
