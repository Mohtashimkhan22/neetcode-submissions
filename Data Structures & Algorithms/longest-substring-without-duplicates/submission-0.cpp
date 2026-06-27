class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        unordered_map<char,int> mp;
        int maxi=0;
        int j=0;
        for(int i=0;i<s.size();i++){
            mp[s[i]]++;
            while(j<=i && mp[s[i]]>1){
                mp[s[j]]--;
                j++;
            }
            
            maxi=max(maxi,i-j+1);
        }
        return maxi;
    }
};
