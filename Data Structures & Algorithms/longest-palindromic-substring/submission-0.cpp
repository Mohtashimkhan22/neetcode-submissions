class Solution {
    string palindrom(string s,int i,int j){
        int n = s.size();
        while(i>=0 && j<n && s[i]==s[j]){
            i--;
            j++;
        }
        return s.substr(i+1,j-i-1);
    }
public:
    string longestPalindrome(string s) {
        int n = s.size();
        string maxi;
        for(int i=0;i<n;i++){
            string l1 = palindrom(s,i,i);
            string l2 = palindrom(s,i,i+1);
            if(maxi.size()<l2.size()){
                maxi=l2;
            }
            if(maxi.size()<l1.size()){
                maxi=l1;
            }
        }
        return maxi;
    }
};