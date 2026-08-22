class Solution {
public:
    bool mergeTriplets(vector<vector<int>>& triplets, vector<int>& target) {
        int m=0,n=0,o=0;
        int x = target[0];
        int y = target[1];
        int z = target[2];
        for(int i=0;i<triplets.size();i++){
            int a = triplets[i][0];
            int b = triplets[i][1];
            int c = triplets[i][2];
            if(a>x || b>y || c>z) continue;
            m = max(m,a);
            n = max(n,b);
            o = max(o,c);
        }
        vector<int> arr = {m,n,o};
        if(target==arr) return true;
        return false;
    }
};
