class Solution {
    bool checker(unordered_map<char,int> freq1, unordered_map<char,int> freq2){
        for(auto it : freq2){
            if(it.second>freq1[it.first]) return false;
        }
        return true;
    }
public:
    string minWindow(string s, string t) {
        int s1 = s.length();
        int s2 = t.length();

        if (s.length() < t.length()) {
            return "";
        }
        unordered_map<char,int> freq2;
        for(auto it : t) freq2[it]++;
        int ans = INT_MAX;
        string str = "";
        for(int i=0;i<s1;i++){
            unordered_map<char,int> freq1;
            for(int j=i;j<s1;j++){
                freq1[s[j]]++;
                if(checker(freq1,freq2) && ans>(j-i+1)){
                    ans=j-i+1;
                    str=s.substr(i,ans);
                    break;
                }
            }
        }
        return str;
    }
};
