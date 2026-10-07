class Solution {
    void solver(int i,int &sum,int x_or,vector<int>& nums){
        int n = nums.size();
        if(i==n){
            sum+=x_or;
            return;
        }

        solver(i+1,sum,x_or^nums[i],nums);
        solver(i+1,sum,x_or,nums);
        
    }
public:
    int subsetXORSum(vector<int>& nums) {
        int n = nums.size();
        int sum = 0;
        int x_or = 0;
        // unordered_set<int> st;
        solver(0,sum,x_or,nums);
        return sum;
    }
};