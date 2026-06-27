class Solution {
public:
    vector<int> productExceptSelf(vector<int>& nums) {
        int n = nums.size();
        vector<int> res1(n,1);
        for(int i=1;i<n;i++){
            res1[i]=res1[i-1]*nums[i-1];
        }
        // for(auto it : res1) cout<<it<<" ";
        vector<int> res2(n,1);
        for(int i=n-2;i>=0;i--){
            res2[i]=res2[i+1]*nums[i+1];
        }
        vector<int> res(n,1);
        for(int i=0;i<n;i++){
            res[i]=res1[i]*res2[i];
        }
        // for(auto it : res2) cout<<it<<" ";
        return res;
    }
};
