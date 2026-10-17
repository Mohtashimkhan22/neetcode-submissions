class Solution {
    void solver(vector<bool> &vis,vector<vector<int>> &res,vector<int> &curr,vector<int> &nums,int n){
        if(curr.size()==n){
            res.push_back(curr);
            return;
        }
        for(int i=0;i<n;i++){
            if(vis[i]) continue;
            if(i>0 && nums[i]==nums[i-1] && !vis[i-1]) continue;

            vis[i]=true;
            curr.push_back(nums[i]);
            solver(vis,res,curr,nums,n);
            curr.pop_back();
            vis[i]=false;
        }
        return ;
    }
public:
    vector<vector<int>> permuteUnique(vector<int>& nums) {
        sort(nums.begin(),nums.end());
        int n = nums.size();
        vector<vector<int>> res;
        vector<int> curr;
        vector<bool> vis(n,false);
        
        solver(vis,res,curr,nums,n);
        return res;
    }
};