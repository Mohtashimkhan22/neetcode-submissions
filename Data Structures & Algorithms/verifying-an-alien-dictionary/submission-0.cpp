class Solution {
public:
    bool isAlienSorted(vector<string>& words, string order) {

        for(int i=1;i<words.size();i++){
            int a=0,b=0;
            string s1 = words[i-1];
            string s2 = words[i];
            while(a<s1.size() && b<s2.size()){
                bool flag = false;
                if(s1[a]!=s2[b]){
                    for(int k=0;k<26;k++){
                        if(order[k]==s1[a] && s2[b]=='*'){
                            return false;
                        }
                        else if(order[k]==s1[a] && s2[b]!='*'){
                            flag=true;
                            break;
                        }
                        else if(order[k]==s2[b]) s2[b]='*';
                    }
                }
                if(flag) break;
                a++;
                b++;
            }
            if(a!=s1.size() && b==s2.size()) return false;
        }
        return true;
    }
};