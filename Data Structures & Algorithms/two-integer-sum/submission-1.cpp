class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        for(int i=0;i<nums.size()-1;i++){
            int diff = target - nums[i];
            cout<<diff<<" ";
            for(int j=i+1;j<nums.size();j++){
                if(diff==nums[j]) return {i,j};
            }
        }
        return {};
    }
};
