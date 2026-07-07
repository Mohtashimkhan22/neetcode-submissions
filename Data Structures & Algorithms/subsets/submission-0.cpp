class Solution {
    void solver(int i,vector<int>& nums, vector<vector<int>>& res, vector<int>& ans){
        int n = nums.size();
        // if(ans.size() == n){
        //     res.push_back(ans);
        //     return;
        // }
        for(int j=i;j<n;j++){
            ans.push_back(nums[j]);
            res.push_back(ans);
            solver(j+1,nums,res,ans);
            ans.pop_back();
        }
    }
public:
    vector<vector<int>> subsets(vector<int>& nums) {
        vector<int> ans;
        vector<vector<int>> res;
        res.push_back(ans);
        solver(0,nums,res,ans);
        return res;
    }
};
