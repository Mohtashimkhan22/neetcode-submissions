class Solution {
    int solver(int i,int n,vector<int> &dp){
        if(i==n) return 1;
        if(i>n) return 0;
        if(dp[i]!=-1) return dp[i];
        
        return dp[i] = solver(i+1,n,dp)+solver(i+2,n,dp);
    }
public:
    int climbStairs(int n) {
        vector<int> dp(n+1,-1);
        return solver(0,n,dp);
    }
};
