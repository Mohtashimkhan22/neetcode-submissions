class Solution {
    int solver(int i,vector<int>& nums,vector<int>& dp){
        int n = nums.size();
        if(i==n-1) return true;
        if(i>=n) return false;
        if(dp[i]!=-1) return dp[i];
        bool ans = false;
        for(int j=nums[i];j>0;j--){
            ans = ans || solver(i+j,nums,dp);
        }
        return dp[i]=ans;
    }
public:
    bool canJump(vector<int>& nums) {
        int n = nums.size();
        if(n==1) return true;
        vector<int> dp(n+1,-1);
        return solver(0,nums,dp);
    }
};
