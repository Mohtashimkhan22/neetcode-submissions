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
        if(n==1) return nums[0];
        vector<int> dp(n+1,-1);
        dp[0]=nums[0];
        dp[1]=max(nums[1],dp[0]);
        for(int i=2;i<n;i++){
            int taken = nums[i]+dp[i-2];
            int notTaken = dp[i-1];
            dp[i]=max(taken,notTaken);
        }
        return dp[n-1];
        // return solver(0,nums,dp);
    }
};
