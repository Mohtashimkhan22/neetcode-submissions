class Solution {
public:
    bool validWordAbbreviation(string word, string abbr) {
        int j=0,i=0;
        int n = word.size();
        int m = abbr.size();
        while(j<m){
            if(i>=n) return false;
            if(isalpha(abbr[j])){
                if(abbr[j]!=word[i]) return false;
                i++;
                j++;
            }
            else{
                if(abbr[j]=='0') return false;
                int num = 0;
                while(j<m && isdigit(abbr[j])){
                    num = num*10 + abbr[j]-'0';
                    j++;
                }
                i+=num;
            }
        }
        return j==m && i==n;
    }
};