class Solution {
    int solver(int i,vector<int>& nums,vector<int>& dp){
        int n = nums.size();
        if(i==n-1) return 0;
        if(i>=n) return 99999;
        if(dp[i]!=-1) return dp[i];
        int ans = 99999;
        for(int j=nums[i];j>0;j--){
            ans = min(ans,1 + solver(i+j,nums,dp));
        }
        return dp[i]=ans;
    }
public:
    int jump(vector<int>& nums) {
        int n = nums.size();
        if(n==1) return 0;
        vector<int> dp(n+1,-1);
        return solver(0,nums,dp);
    }
};

