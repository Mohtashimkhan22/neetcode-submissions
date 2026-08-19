class Solution {
    int solver(string s1, string s2, string s3,int i,int j,int k,vector<vector<int>> &dp){
        int n = s1.size();
        int m = s2.size();
        int s = s3.size();
        if(i==n && j==m && k==s) return 1;
        if(dp[i][j]!=-1) return dp[i][j];
        int a=0,b=0;
        if(i<n && s1[i]==s3[k]){
            cout<<s1[i]<<" ";
            a = solver(s1,s2,s3,i+1,j,k+1,dp);
        }
        if(j<m && s2[j]==s3[k]){
            cout<<s2[j]<<" ";
            b = solver(s1,s2,s3,i,j+1,k+1,dp);
        }
        return dp[i][j]=a|b;
    }
public:
    bool isInterleave(string s1, string s2, string s3) {
        int n = s1.size();
        int m = s2.size();
        vector<vector<int>> dp(n+1,vector<int>(m+1,-1));
        return solver(s1,s2,s3,0,0,0,dp);
    }
};
