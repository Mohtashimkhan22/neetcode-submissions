class Solution {
    void solver(vector<vector<int>> &res,vector<int> &curr,int i,int n,int k){
        if(curr.size()==k){
            res.push_back(curr);
            return;
        }
        if(i<=n){
            curr.push_back(i);;
            solver(res,curr,i+1,n,k);
            curr.pop_back();
            solver(res,curr,i+1,n,k);
        }
        return ;
    }
public:
    vector<vector<int>> combine(int n, int k) {
        vector<vector<int>> res;
        vector<int> curr;
        unordered_set<int> arr;
        solver(res,curr,1,n,k);
        return res;
    }
};