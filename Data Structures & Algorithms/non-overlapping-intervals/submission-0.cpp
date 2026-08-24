class Solution {
public:
    int eraseOverlapIntervals(vector<vector<int>>& intervals) {
        sort(intervals.begin(),intervals.end(),[](auto a,auto b){
            if(a[1]==b[1]) return a[0]<b[0];
            return a[1]<b[1];
        });
        vector<vector<int>> result;
        int count = 0;
        result.push_back(intervals[0]);
        for(int i=1;i<intervals.size();i++){
            vector<int> temp = result.back();
            if(temp[1]>intervals[i][0]){
                count++;
            }
            else{
                result.push_back(intervals[i]);
            }
        }
        return count;
    }
};
