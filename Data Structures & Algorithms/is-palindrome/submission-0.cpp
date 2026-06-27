class Solution {
public:
    bool isPalindrome(string s) {
        int n = s.size();
        for(int i=0,j=n-1;i<j;){
            if(!isalnum(s[i])){
                i++;
                continue;
            }
            if(!isalnum(s[j])){
                j--;
                continue;
            }
            else{
                char c1 = tolower(s[i]);
                char c2 = tolower(s[j]);
                if(c1!=c2) return false;
                i++;
                j--;
            }
        }
        return true;
    }
};