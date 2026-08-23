class Solution {
    int solver(int i,int j,string s,string p,vector<vector<int>> &dp){
        int n = s.size();
        int m = p.size();
        if(j==m) return i==n;
        if(dp[i][j]!=-1) return dp[i][j];
        
        bool firstmatch = (i<n && (s[i]==p[j] || p[j]=='.'));

        if(j+1<m && p[j+1]=='*'){
            bool zero = solver(i,j+2,s,p,dp);
            bool oneOrMore = false;
            if(firstmatch) oneOrMore = solver(i+1,j,s,p,dp);
            return dp[i][j] = (zero || oneOrMore);
        }
        
        if(firstmatch){
            return dp[i][j] = solver(i+1,j+1,s,p,dp);
        }
        return dp[i][j]=false;
    }
public:
    bool isMatch(string s, string p) {
        int n = s.size();
        int m = p.size();
        vector<vector<int>> dp(n+1,vector<int>(m+1,-1));
        return solver(0,0,s,p,dp);
    }
};
