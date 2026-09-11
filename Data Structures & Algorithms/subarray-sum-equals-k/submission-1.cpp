class Solution {
public:
    int subarraySum(vector<int>& nums, int k) {
        unordered_map<int,int> mp;
        int n = nums.size();
        int sum = 0;
        mp[0]=1;
        int count = 0;
        for(int i=0;i<n;i++){
            sum+=nums[i];
            int diff = sum-k;
            if(mp.count(diff)) count+=mp[diff];
            mp[sum]++;
        }
        return count;
    }
};