class Solution {
public:
    int ladderLength(string beginWord, string endWord, vector<string>& wordList) {

        unordered_set<string> setList(wordList.begin(),wordList.end());

        if(setList.count(endWord)==0) return 0;
        int n = beginWord.size();
        queue<pair<string,int>> q;
        q.push({beginWord,1});

        while(!q.empty()){
            string str = q.front().first;
            int step = q.front().second;
            q.pop();
            if(str==endWord) return step;
            for(int i=0;i<n;i++){
                char c = str[i];
                for(char ch='a';ch<='z';ch++){
                    str[i]=ch;
                    if(setList.count(str)){
                        q.push({str,step+1});
                        setList.erase(str);
                    }
                    
                }
                str[i]=c;
            }
        }
        return 0;
    }
};
