class Solution {
public:
    int findJudge(int n, vector<vector<int>>& trust) {
        vector<int> inorder(n+1,0),outgoing(n+1,0);
        for(auto it : trust){
            inorder[it[1]]++;
            outgoing[it[0]]++;
        }
        int count=0;
        int val = 0;
        int judge = -1;
        for(int i=1;i<=n;i++){
            if(inorder[i]==n-1 && outgoing[i]==0){ 
                return i;
            }
        }
        // if(count>1) return -1;
        // if(val!=n-1) return -1;
        return -1;
    }
};