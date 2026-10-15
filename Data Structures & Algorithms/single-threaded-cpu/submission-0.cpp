class Solution {
public:
    vector<int> getOrder(vector<vector<int>>& tasks) {
        vector<vector<int>> arr;
        int n = tasks.size();
        for(int i=0;i<n;i++){
            arr.push_back({tasks[i][0],tasks[i][1],i});
        }
        sort(arr.begin(), arr.end());

        int time = 0;
        priority_queue<pair<int,int>,vector<pair<int,int>>,greater<pair<int,int>>> pq;
        int i=0;
        vector<int> res;
        while(i<n || !pq.empty()){
            if(i<n && time<arr[i][0]) time = arr[i][0];

            while(i<n && time>=arr[i][0]){
                pq.push({arr[i][1],arr[i][2]});
                i++;
            }
            auto it = pq.top();
            time+=it.first;
            pq.pop();
            res.push_back(it.second);
        }
        return res;
    }
};