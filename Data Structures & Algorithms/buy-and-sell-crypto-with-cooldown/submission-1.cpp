class Solution {
    int solver(vector<int>& prices,vector<vector<int>> &dp,int idx,int buy){
        int n = prices.size();
        if(idx>=n) return 0;
        if(dp[idx][buy]!=-1) return dp[idx][buy];
        if(buy){
            int sell = prices[idx] + solver(prices,dp,idx+2,0);
            int skip = solver(prices,dp,idx+1,1);
            dp[idx][buy] = max(sell,skip);
        }
        else{
            int take = -prices[idx] + solver(prices,dp,idx+1,1);
            int skip = solver(prices,dp,idx+1,0);
            dp[idx][buy]=max(take,skip);
        }
        return dp[idx][buy];
    }
public:
    int maxProfit(vector<int>& prices) {
        int n = prices.size();
        vector<vector<int>> dp(n+1,vector<int>(2,-1));
        return solver(prices,dp,0,0);
    }
};
