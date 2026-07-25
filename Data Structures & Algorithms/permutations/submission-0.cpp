class Solution {
    void solver(vector<int>& nums,vector<int>& ans,vector<vector<int>> &res,vector<bool> &vis){
        if(nums.size()==ans.size()){
            res.push_back(ans);
            return;
        }
        int n = nums.size();
        for(int j=0;j<n;j++){
            if(vis[j]) continue;
            vis[j]=true;
            ans.push_back(nums[j]);
            solver(nums,ans,res,vis);
            ans.pop_back();
            vis[j]=false;
        }
    }
public:
    vector<vector<int>> permute(vector<int>& nums) {
        int n = nums.size();
        vector<int> ans;
        vector<bool> vis(n,false); 
        vector<vector<int>> res;
        // for(int i=0;i<n;i++)
        solver(nums,ans,res,vis);
        return res;
    }
};
