class Solution {
public:
    string longestCommonPrefix(vector<string>& strs) {
        string ans = strs[0];
        for(string it : strs){
            string temp = "";
            for(int j=0;j<min(it.size(),ans.size());j++){
                if(ans[j]!=it[j]) break;
                temp+=ans[j];
            }
            ans = temp;
        }
        return ans;
    }
};