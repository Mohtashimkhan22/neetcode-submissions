class Solution {
public:
    vector<int> maxSlidingWindow(vector<int>& nums, int k) {
        unordered_map<int,int> mp;
        priority_queue<int> pq;
        int l = 0;
        vector<int> ans;
        
        for(int r=0;r<nums.size();r++){
            mp[nums[r]]++;
            pq.push(nums[r]);
            while(!mp.count(pq.top())) pq.pop();
            
            if(r>=k-1){
                ans.push_back(pq.top());
                mp[nums[l]]--;
                if(mp[nums[l]]==0){
                    mp.erase(nums[l]);
                }
                l++;
            }
        }
        return ans;
    }
};
