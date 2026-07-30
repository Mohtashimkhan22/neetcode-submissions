class Solution {
public:
    vector<int> findOrder(int numCourses, vector<vector<int>>& prerequisites) {
    int n = numCourses;
        vector<vector<int>> adj(n);
        vector<int> inorder(n,0);
        for(auto it : prerequisites){
            adj[it[0]].push_back(it[1]);
            inorder[it[1]]++;
        }
        queue<int> q;
        for(int i=0;i<n;i++){
            if(inorder[i]==0) q.push(i);
        }
        vector<int> ans;
        while(!q.empty()){
            int node = q.front();
            q.pop();
            ans.push_back(node);
            for(auto it : adj[node]){
                inorder[it]--;
                if(inorder[it]==0) q.push(it);
            }
        }
        if(ans.size()!=n) return {};
        reverse(ans.begin(),ans.end());
        return ans;
    }
};
