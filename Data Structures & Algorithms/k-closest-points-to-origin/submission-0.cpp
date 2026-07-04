class Solution {
public:
    vector<vector<int>> kClosest(vector<vector<int>>& points, int k) {
        priority_queue<pair<double,vector<int>>,vector<pair<double,vector<int>>>,greater<pair<double,vector<int>>>> pq;
        for(auto it : points){
            double d = sqrt(it[0]*it[0]+it[1]*it[1]);
            pq.push({d,it});
        }
        vector<vector<int>> ans;
        while(!pq.empty() && k--){
            auto it = pq.top().second;
            pq.pop();
            ans.push_back(it);
        }
        return ans;
    }
};
