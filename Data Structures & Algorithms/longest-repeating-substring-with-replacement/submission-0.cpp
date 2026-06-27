class Solution {
public:
    int characterReplacement(string s, int k) {
        vector<int> freq(26,0);
        int j=0,ans=0;
        for(int i=0;i<s.size();i++){
            freq[s[i]-'A']++;
            int maxi = 0;
            for(int j=0;j<26;j++){
                maxi=max(maxi,freq[j]);
            }
            int total = i-j+1;
            if(total-maxi<=k){
                ans=max(ans,total);
            }
            else{
                // while(total-maxi>k){

                // }
                freq[s[j]-'A']--;
                j++;
            }
        }
        return ans;
    }
};
