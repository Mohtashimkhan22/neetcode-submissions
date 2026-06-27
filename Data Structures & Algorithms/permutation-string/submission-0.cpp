class Solution {
public:
    bool checkInclusion(string s1, string s2) {
        vector<int> freq(26,0);
        for(char ch : s1) freq[ch-'a']++;
        int size1 = s1.size();
        int size2 = s2.size();
        if(size1>size2) return false;
        for(int i=0;i<=size2-size1;i++){
            vector<int> fr(26,0);
            for(int j=0;j<size1;j++){
                fr[s2[j+i]-'a']++;
            }
            if(fr==freq) return true;
        }
        return false;
    }
};