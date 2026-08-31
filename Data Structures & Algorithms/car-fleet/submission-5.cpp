class Solution {
public:
    int carFleet(int target, vector<int>& position, vector<int>& speed) {
        int n = position.size();
        vector<pair<int,int>> arr(n);
        for(int i=0;i<n;i++){
            arr[i]={position[i],speed[i]};
        }
        sort(arr.begin(),arr.end());
        vector<double> times(n);
        for(int i=0;i<n;i++){
            times[i] = double(target-arr[i].first)/arr[i].second;
        }
        for(auto it : times) cout<<it<<" ";
        int count = 1;
        double maxi = times[n-1];
        for(int i=n-2;i>=0;i--){
            if(times[i]>maxi){
                maxi = times[i];
                count++;
            }
        }
        return count;
    }
};
