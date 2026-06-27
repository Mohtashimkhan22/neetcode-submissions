class Solution {
public:
    int longestConsecutive(vector<int>& nums) {
        int ans = 0;
        unordered_set<int> st;
        for(int it : nums) st.insert(it);
        for(auto it : nums){
            int curr = 1;
            if(st.count(it-1)) continue;
            while(st.count(it+1)){
                curr++;
                it++;
            } 
            ans=max(ans,curr);
        }
        return ans;
    }
};
