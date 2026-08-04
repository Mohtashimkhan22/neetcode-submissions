class Solution {
public:
    string foreignDictionary(vector<string>& words) {
        unordered_map<char,unordered_set<char>> mp;
        unordered_map<char,int> inorder;
        for(string str : words){
            int n = str.size(); 
            for(int i=0;i<str.size();i++){
                // mp[c].insert(str[i]);
                // inorder[str[i]]=0;
                char c = str[i];
                mp[c];
                inorder[c]=0;
            }

        }
        for(int i=1;i<words.size();i++){
            string s1 = words[i-1];
            string s2 = words[i];
            if(s1.size()>s2.size() && s1.contains(s2))
                return "";
            for(int j=0;j<s1.size();j++){
                if(s1[j]==s2[j]) continue;
                else{
                    mp[s1[j]].insert(s2[j]);
                    break;
                }
            }
            
        }
        for(auto& [key, value] : mp){
            for(auto it : value){
                inorder[it]++;
            }
        }
        // for(auto& [key, value] : inorder){
        //     cout<<key<<" "<<value<<endl;
        // }
        string ans = "";
        queue<char> q;
        for(auto& [key, value] : inorder){
            if(value==0){
                q.push(key);
            }
        }
        while(!q.empty()){
            char node = q.front();
            q.pop();
            ans+=node;
            for(auto it : mp[node]){
                inorder[it]--;
                if(inorder[it]==0){
                    q.push(it);
                }
            }
        }
        if(ans.size()==mp.size()) return ans;
        return "";
    }
};
