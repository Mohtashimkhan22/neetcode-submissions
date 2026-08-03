class Solution {
public:
    vector<string> findItinerary(vector<vector<string>>& tickets) {
        unordered_map<string,vector<string>> adj;
        for(auto it : tickets){
            adj[it[0]].push_back(it[1]);
        }
        for(auto &[_,st] : adj){
            sort(st.begin(),st.end(),greater<string>());
        }
        vector<string> ans;
        stack<string> st;
        st.push("JFK");
        unordered_set<string> vis;
        while(!st.empty()){
            string node = st.top();
            if(!adj[node].empty() && !st.empty()){
                st.push(adj[node].back());
                adj[node].pop_back();
            }
            else{
                cout<<node<<" ";
                ans.push_back(node);
                st.pop();

            }
        }
        reverse(ans.begin(),ans.end());
        return ans;
    }
};
