class Solution {
public:
    bool isNStraightHand(vector<int>& hand, int groupSize) {
        int n = hand.size();
        if(n%groupSize!=0) return false;
        int no = n/groupSize;
        if(no==n) return true;
        sort(hand.begin(),hand.end());
        unordered_map<int,int> mp;
        for(auto it : hand) mp[it]++;
        // 1/ 2/ 2/ 3/ 3/ 4/ 4/ 5/
        for(int it : hand){
            // cout<<it<<" ";
            if(mp[it]==0) continue;
            for(int j=0;j<groupSize;j++){
                if(mp[it+j]==0) return false;
                // cout<<mp[it+j]<<" ";
                mp[it+j]--;
            }
        }
        return true;
    }
};
