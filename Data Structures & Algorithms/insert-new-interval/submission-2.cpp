class Solution {
public:
    vector<vector<int>> insert(vector<vector<int>>& intervals, vector<int>& newInterval) {
        int n = intervals.size();
        int i=0,j=0;
        vector<vector<int>> result;
        while(i<n && intervals[i][1]<newInterval[0]){
            result.push_back(intervals[i]);
            i++;
            // cout<<i<<" ";
        }
        if(i==n || intervals[i][0]>newInterval[1]){
            result.push_back(newInterval);
        }
        else{
            int mini = min(newInterval[0],intervals[i][0]);
            int maxi = max(newInterval[1],intervals[i][1]);
            cout<<"in overlap"<<" ";
            while(i<n && intervals[i][0]<=maxi){
                i++;
            }
            cout<<i<<" ";
            maxi = max(maxi,intervals[i-1][1]);
            result.push_back({mini,maxi});
        }
        while(i<n){
            result.push_back(intervals[i]);
            i++;   
        }
        return result;
    }
};
