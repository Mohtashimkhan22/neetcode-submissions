class Solution {
public:
    int shipWithinDays(vector<int>& weights, int days) {
        int l = *max_element(weights.begin(),weights.end());
        int h = accumulate(weights.begin(),weights.end(),0);
        int n = weights.size(),ans=0;
        while(l<=h){
            int mid = l+(h-l)/2;
            int count=0,i=0;
            while(i<n){
                count++;
                int sum = 0;
                while(i<n && sum<mid){
                    sum+=weights[i];
                    i++;
                }
                if(sum>mid) i--;
                // cout<<sum<<" "<<i<<" ";
            }
            cout<<endl;
            // cout<<count<<" "<<mid<<endl;
            if(count<=days){
                h=mid-1;
                ans=mid;
            }
            else if(count>days) l=mid+1;
        }
        return l;
    }
};