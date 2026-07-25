class Solution {
    void solver(vector<int>& nums,vector<vector<int>>& res,int i,int last){
        int n = nums.size();
        
        if(i>=n) return;
        int s = res.size();
        if(i>0 && nums[i]==nums[i-1]){
            for(int j=s-last;j<s;j++){
                vector<int> temp = res[j];
                temp.push_back(nums[i]);
                res.push_back(temp);
            }
        }
        else {
            for(int j=0;j<s;j++){
                vector<int> temp = res[j];
                temp.push_back(nums[i]);
                res.push_back(temp);
            }
        }
        int s1 = res.size();
        last = s1-s;
        solver(nums,res,i+1,last);
    }
public:
    vector<vector<int>> subsetsWithDup(vector<int>& nums) {
        sort(nums.begin(),nums.end());
        vector<int> temp;
        vector<vector<int>> res;
        res.push_back(temp);
        solver(nums,res,0,1);
        return res;
    }
};
