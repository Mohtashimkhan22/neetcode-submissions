class Solution {
public:
    vector<int> partitionLabels(string s) {
        unordered_map<char,int> freq;
        int n=s.size();
        for(int i=0;i<n;i++) freq[s[i]]=i;
        vector<int> ans;
        int start=0,end=0;
        for(int i=0;i<n;i++){
            end = max(end,freq[s[i]]);
            if(i==end){
                cout<<i<<" ";
                ans.push_back(end-start+1);
                start=i+1;
            }
        }
        return ans;
    }
};
