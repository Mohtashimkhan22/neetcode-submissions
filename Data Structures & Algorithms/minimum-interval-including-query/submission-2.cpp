class Solution {
public:
    vector<int> minInterval(vector<vector<int>>& intervals, vector<int>& queries) {
        sort(intervals.begin(), intervals.end());

        vector<int> sortedQueries = queries;
        sort(sortedQueries.begin(), sortedQueries.end());

        priority_queue<
            pair<int, int>,
            vector<pair<int, int>>,
            greater<pair<int, int>>
        > pq;

        unordered_map<int, int> mp;

        int i = 0;
        int n = intervals.size();

        for (int q : sortedQueries) {

            // Add every interval that can potentially contain q
            while (i < n && intervals[i][0] <= q) {
                int l = intervals[i][0];
                int r = intervals[i][1];

                pq.push({r - l + 1, r});
                i++;
            }

            // Remove intervals that don't contain q anymore
            while (!pq.empty() && pq.top().second < q) {
                pq.pop();
            }

            if (pq.empty()) {
                mp[q] = -1;
            } else {
                mp[q] = pq.top().first;
            }
        }

        vector<int> ans;

        for (int q : queries) {
            ans.push_back(mp[q]);
        }

        return ans;
    }
};
