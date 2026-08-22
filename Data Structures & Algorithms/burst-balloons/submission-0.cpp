class Solution {
    int solver(int l,int r,vector<int> &arr,vector<vector<int>> &dp){
        if (l + 1 == r)
            return 0;
        if(dp[l][r]!=-1) return dp[l][r];
        int ans = 0;
        for(int k=l+1;k<r;k++){
            ans=max(ans,arr[l]*arr[k]*arr[r]+solver(l,k,arr,dp)+solver(k,r,arr,dp));
            // cout<<ans<<" ";
        }
        return dp[l][r]=ans;
    }
public:
    int maxCoins(vector<int>& nums) {
        vector<int> arr=nums;
        arr.insert(arr.begin(),1);
        arr.insert(arr.end(),1);
        // for(auto it : arr) cout<<it<<" ";
        int n = arr.size();
        vector<vector<int>> dp(n,vector<int>(n,-1));
        return solver(0,n-1,arr,dp);
    }
};
