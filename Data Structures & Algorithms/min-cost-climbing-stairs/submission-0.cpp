class Solution {
    int solver(int i,int n,vector<int> &dp,vector<int>& cost){
        if(i==n) return cost[i];
        if(i>n) return 0;
        if(dp[i]!=-1) return dp[i];
        
        return dp[i] = cost[i]+min(solver(i+1,n,dp,cost),solver(i+2,n,dp,cost));
    }
public:
    int minCostClimbingStairs(vector<int>& cost) {
        int n = cost.size();
        vector<int> dp(n+1,-1);
        return min(solver(0,n-1,dp,cost),solver(1,n-1,dp,cost));
    }
};
