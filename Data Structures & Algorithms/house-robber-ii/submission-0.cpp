class Solution {
    int solver(int i, vector<int>& nums, vector<int>& dp) {
        if (i >= nums.size())
            return 0;

        if (dp[i] != -1)
            return dp[i];

        int take = nums[i] + solver(i + 2, nums, dp);
        int skip = solver(i + 1, nums, dp);

        return dp[i] = max(take, skip);
    }

public:
    int rob(vector<int>& nums) {
        int n = nums.size();

        if (n == 1)
            return nums[0];

        vector<int> first(nums.begin(), nums.end() - 1);
        vector<int> second(nums.begin() + 1, nums.end());

        vector<int> dp1(first.size(), -1);
        vector<int> dp2(second.size(), -1);

        return max(solver(0, first, dp1), solver(0, second, dp2));
    }
};