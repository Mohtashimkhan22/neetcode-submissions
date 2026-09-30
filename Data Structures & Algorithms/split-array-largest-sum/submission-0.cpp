class Solution {
public:
    int splitArray(vector<int>& nums, int k) {
        int l = *max_element(nums.begin(),nums.end());
        int h = accumulate(nums.begin(),nums.end(),0);
        int n = nums.size(),ans=0;
        while(l<=h){
            int mid = l+(h-l)/2;
            int count=0,i=0;
            while(i<n){
                count++;
                int sum = 0;
                while(i<n && sum<mid){
                    sum+=nums[i];
                    i++;
                }
                if(sum>mid) i--;
            }
            cout<<endl;
            if(count<=k){
                h=mid-1;
                ans=mid;
            }
            else if(count>k) l=mid+1;
        }
        return l;
    }
};