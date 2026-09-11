class Solution {
public:
    vector<int> majorityElement(vector<int>& nums) {
        int n = nums.size();
        int ele1, cnt1=0;
        int ele2, cnt2=0;
        for(int i=0;i<n;i++){
            if(cnt1==0){
                ele1=nums[i];
                cnt1++;
            }
            else if(ele1==nums[i]) cnt1++;
            else if(cnt2==0){
                ele2=nums[i];
                cnt2++;
            }
            else if(ele2==nums[i]) cnt2++;
            else{
                cnt1--;
                cnt2--;
            }
        }
        vector<int> res;
        if(cnt2>0){
            int count=0;
            for(auto it : nums) if(it==ele2) count++;
            if(n/3<count) res.push_back(ele2);
        }
        int count=0;
        for(auto it : nums) if(it==ele1) count++;
        if(n/3<count) res.push_back(ele1);
        return res;
    }
};