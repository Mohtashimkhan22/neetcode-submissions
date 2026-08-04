class Solution {
    int solver(int i,vector<int>& nums,vector<int> &dp){
        int n = nums.size();
        if(i>=n) return 0;
        if(dp[i]!=-1) return dp[i];
        int taken = nums[i]+solver(i+2,nums,dp);
        int notTaken = solver(i+1,nums,dp);
        return dp[i]=max(taken,notTaken);
    }
public:
    int rob(vector<int>& nums) {
        int n = nums.size();
        vector<int> dp(n+1,-1);
        return solver(0,nums,dp);
    }
};
