class Solution {
    void solver(vector<int>& path, vector<int>& nums, int target,
                vector<vector<int>>& ans, int sum, int idx) {

        if (sum == target) {
            ans.push_back(path);
            return;
        }

        if (sum > target) return;

        for (int i = idx; i < nums.size(); i++) {

            if (i > idx && nums[i] == nums[i - 1])
                continue;

            path.push_back(nums[i]);
            solver(path, nums, target, ans, sum + nums[i], i + 1);
            path.pop_back();
        }
    }

public:
    vector<vector<int>> combinationSum2(vector<int>& nums, int target) {
        sort(nums.begin(), nums.end());

        vector<vector<int>> ans;
        vector<int> path;

        solver(path, nums, target, ans, 0, 0);

        return ans;
    }
};