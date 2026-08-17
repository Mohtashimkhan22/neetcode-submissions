class Solution {
    int solver(int target,vector<int> &nums,vector<vector<int>> &dp,int i,int sum,int totalsum){
        int n = nums.size();
        if(i==n) return sum==target;
        if(dp[i][sum+totalsum]!=-1) return dp[i][sum+totalsum];
        int add = solver(target,nums,dp,i+1,sum-nums[i],totalsum);
        int sub = solver(target,nums,dp,i+1,sum+nums[i],totalsum);
        return dp[i][sum+totalsum]=add+sub;
    }
public:
    int findTargetSumWays(vector<int>& nums, int target) {
        int n = nums.size();
        int totalsum = accumulate(nums.begin(), nums.end(), 0);

        if (abs(target) > totalsum)
            return 0;
        vector<vector<int>> dp(n, vector<int>(2*totalsum + 1, -1));
        return solver(target,nums,dp,0,0,totalsum);
    }
};
