class Solution {
    void solver(vector<int> &elements,vector<int>& nums, int &target,vector<vector<int>> &st,int sum,int i){
        int n = nums.size();
        if(i==n) return;
        if(sum>target) return;
        
        if(sum==target){
            st.push_back(elements);
            return;
        }
        elements.push_back(nums[i]);
        solver(elements,nums,target,st,sum+nums[i],i);
        elements.pop_back();
        solver(elements,nums,target,st,sum,i+1);
    }
public:
    vector<vector<int>> combinationSum(vector<int>& nums, int target) {
        vector<vector<int>> st;
        
        int n = nums.size();
        // for(int i=0;i<n;i++){
            vector<int> elements;
            solver(elements,nums,target,st,0,0);
        // }
        
        return st;
    }
};
