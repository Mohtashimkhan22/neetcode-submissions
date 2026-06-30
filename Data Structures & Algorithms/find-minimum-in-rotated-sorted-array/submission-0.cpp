class Solution {
public:
    int findMin(vector<int> &nums) {
        int l=0,r=nums.size()-1;
        int ans = INT_MAX;
        while(l<=r){
            int mid = (l+r)/2;
            ans=min(min(ans,nums[l]),min(nums[r],nums[mid]));
            if(nums[l]<nums[mid]){
                l=mid+1;
            }
            else{
                r=mid-1;
            }
        }
        return ans;
    }
};
