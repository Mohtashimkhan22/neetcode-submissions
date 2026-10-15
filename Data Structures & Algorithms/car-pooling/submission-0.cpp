class Solution {
public:
    bool carPooling(vector<vector<int>>& trip, int capacity) {
        int n = trip.size();
        sort(trip.begin(),trip.end(),[](const auto &a, const auto &b){
            if(a[1]<b[1]) return true;
            return false;
        });
        priority_queue<pair<int,int>,vector<pair<int,int>>,greater<pair<int,int>>> pq;
        int i=1;
        int currcap = capacity;
        if(capacity<trip[0][0]) return false;
        currcap -= trip[0][0];
        pq.push({trip[0][2],trip[0][0]});
        while(i<n){
            while(!pq.empty() && pq.top().first<=trip[i][1]){
                auto it = pq.top();
                currcap+=it.second;
                pq.pop();
            }
            currcap-=trip[i][0];
            pq.push({trip[i][2],trip[i][0]});
            if(currcap<0) return false;
            i++;
        }
        return true;
    }
};