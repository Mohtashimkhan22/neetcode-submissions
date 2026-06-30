class Solution {
public:
    int minEatingSpeed(vector<int>& piles, int h) {
        int r = *max_element(piles.begin(),piles.end());
        int l=1;
        while(l<=r){
            int mid = l + (r-l)/2;
            int time = 0;
            for(int i=0;i<piles.size();i++){
                double t = (double)piles[i]/mid;
                time+=ceil(t);
            }
            // cout<<time<<" ";
            if(time>h) l=mid+1;
            else r=mid-1;
        }
        return l;
    }
};
