class Solution {
public:
    int majorityElement(vector<int>& nums) {
        int n = nums.size();
        int ele = nums[0];
        int count = 1;
        for(int i=1;i<n;i++){
            if(ele == nums[i]){
                count++;
            }
            else count--;
            if(count==0){
                ele = nums[i];
                count=1;
            }
        }
        // count=0;
        // for(auto it : nums) if(it==ele) count++;
        // if(n/2<count) return -1;
        return ele;
    }
};