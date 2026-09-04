class Solution {
public:
    bool checkInclusion(string s1, string s2) {
        vector<int> freq(26,0);
        int m = s1.size();
        for(int i=0;i<m;i++){
            freq[s1[i]-'a']++;
        }
        int n = s2.size();
        for(int i=0;i<n;i++){
            vector<int> temp = freq;
            for(int j=i;j<min(n,i+m);j++){
                temp[s2[j]-'a']--;
            }
            bool flag = true;
            for(int j=0;j<26;j++){
                if(temp[j]) flag=false;

            }
            if(flag) return true;
        }
        return false;
    }
};
