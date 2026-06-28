class Solution {
public:
    vector<int> dailyTemperatures(vector<int>& temperatures) {
        int n = temperatures.size();
        vector<int> ans(n,0);
        for(int i=0;i<n;i++){
            int j=i+1;
            while(j<n && temperatures[j]<=temperatures[i]){
                j++;
            }
            if(j<n)ans[i]=j-i;
        }
        return ans;
    }
};
