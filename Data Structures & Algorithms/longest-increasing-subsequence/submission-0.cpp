class Solution {
    int solver(int i, vector<int> &nums,vector<vector<int>> &dp,int prev){
        int n = nums.size();
        if(i==n) return 0;
        if(dp[i][prev+1]!=-1) return dp[i][prev+1];
        int taken  = 0;
        if(prev==-1 || nums[prev] < nums[i]){
            taken = 1 + solver(i+1,nums,dp,i);
        }
        int nottaken = solver(i+1,nums,dp,prev);
        return dp[i][prev+1] = max(taken,nottaken);
    }
public:
    int lengthOfLIS(vector<int>& nums) {
        int n = nums.size();
        vector<vector<int>> dp(n+1,vector<int>(n+1,-1));
        return solver(0,nums,dp,-1);
    }
};
