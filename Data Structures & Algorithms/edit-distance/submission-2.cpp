class Solution {
    int solver(int i,int j,string word1,string word2,vector<vector<int>> &dp){
        int n = word1.size();
        int m = word2.size();
        if(j==m) return n-i;
        if(i==n) return m-j;
        
        if(dp[i][j]!=-1) return dp[i][j];
        if(word1[i]==word2[j]){
            int tk = solver(i+1,j+1,word1,word2,dp);
            dp[i][j]=tk;
        }
        else {
            int in = 1 + solver(i,j+1,word1,word2,dp);
            int dt = 1 + solver(i+1,j,word1,word2,dp);
            int re = 1 + solver(i+1,j+1,word1,word2,dp);
            dp[i][j]=min({in,dt,re});
        }
        return dp[i][j];
    }
public:
    int minDistance(string word1, string word2) {
        int n = word1.size();
        int m = word2.size();
        vector<vector<int>> dp(n+1,vector<int>(m+1,-1));
        return solver(0,0,word1,word2,dp);
    }
};
