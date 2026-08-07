class Solution {
    bool solver(int i,int amount, vector<int> &nums,vector<vector<int>> &dp){
        int n = nums.size();
        if(i==n) return false;
        if(amount<0) return false;
        if(amount==0) return true;
        if(dp[i][amount]!=-1) return dp[i][amount];
        bool taken  = false;
        if(amount>=nums[i]){
            taken = solver(i+1,amount-nums[i],nums,dp);
        }
        bool nottaken = solver(i+1,amount,nums,dp);
        return dp[i][amount]=taken|nottaken;
    }
public:
    bool canPartition(vector<int>& nums) {
        int sum = 0;
        for(auto it : nums) sum+=it;
        if(sum%2==1) return false;
        int amount = sum/2;
        vector<vector<int>> dp(nums.size()+1,vector<int>(amount+1,-1));
        return solver(0,amount,nums,dp);
    }
};
