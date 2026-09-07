class Solution {
    int pivot(int l,int r,vector<int> &nums){
        int last = nums[r];
        int i=l;
        for(int j=l;j<r;j++){
            if(nums[j]<last){
                swap(nums[i],nums[j]);
                i++;
            }
        }
        swap(nums[i],nums[r]);
        // cout<<i<<" ";
        return i;
    }
    void quicksort(int l,int r,vector<int> &nums){
        if(l>=r) return;
        int idx = pivot(l,r,nums);
        // cout<<idx<<" ";
        quicksort(l,idx-1,nums);
        quicksort(idx+1,r,nums);
    }
public:
    vector<int> sortArray(vector<int>& nums) {
        int n = nums.size();
        quicksort(0,n-1,nums);
        return nums;
    }
};