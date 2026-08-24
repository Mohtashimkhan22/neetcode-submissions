class Solution {
public:
    vector<vector<int>> merge(vector<vector<int>>& intervals) {
        sort(intervals.begin(),intervals.end());
        vector<vector<int>> result;
        result.push_back(intervals[0]);
        for(int i=1;i<intervals.size();i++){
            vector<int> temp = result.back();
            if(temp[1]>=intervals[i][0]){
                result.pop_back();
                result.push_back({min(temp[0],intervals[i][0]),max(temp[1],intervals[i][1])});
            }
            else{
                result.push_back(intervals[i]);
            }
        }
        return result;
    }
};
