class Solution {
public:
    int firstMissingPositive(vector<int>& nums) {
        unordered_set<int> st;
        for(auto it : nums) st.insert(it);
        for(int i=1;i<=nums.size();i++){
            if(st.count(i)==0) return i;
        }
        return nums.size()+1;
    }
};