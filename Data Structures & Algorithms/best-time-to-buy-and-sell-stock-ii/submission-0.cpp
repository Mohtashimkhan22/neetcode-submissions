class Solution {
    int solver(vector<int>& prices,int i,vector<vector<int>> &dp,int flag){
        int n = prices.size();
        if(i==n) return 0;
        if(dp[i][flag]!=-1) return dp[i][flag];
        int ans=0;
        if(flag==0){
            int buy = -prices[i] + solver(prices,i+1,dp,1);
            int notbuy = solver(prices,i+1,dp,flag);
            ans = max(buy,notbuy);
        }
        else if(flag==1){
            int sell = prices[i] + solver(prices,i+1,dp,0);
            int notsell = solver(prices,i+1,dp,flag);
            ans = max(sell,notsell);
        }
        return dp[i][flag]=ans;
    }
public:
    int maxProfit(vector<int>& prices) {
        int n = prices.size();
        vector<vector<int>> dp(n,vector<int>(2,-1));
        return solver(prices,0,dp,0);
    }
};