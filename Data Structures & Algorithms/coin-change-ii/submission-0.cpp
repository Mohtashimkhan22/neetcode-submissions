class Solution {
    int solver(int amount,vector<int> &coins,vector<vector<int>> &dp,int i){
        int n = coins.size();
        if(amount==0) return 1;
        if(i>=n || amount<0) return 0;
        if(dp[i][amount]!=-1) return dp[i][amount];
        int taken = solver(amount-coins[i],coins,dp,i);
        int nottaken = solver(amount,coins,dp,i+1);
        return dp[i][amount]=taken+nottaken;
    }
public:
    int change(int amount, vector<int>& coins) {
        int n = coins.size();
        vector<vector<int>> dp(n+1,vector<int>(amount+1,-1));
        return solver(amount,coins,dp,0);
    }
};
