struct trie{
    trie* child[26];
    trie(){
        for(int i=0;i<26;i++) child[i]=nullptr;
    }
    bool isEnd=false;
};
class WordDictionary {
    trie* parent = new trie();
public:
    WordDictionary() {
        
    }
    
    void addWord(string word) {
        trie* temp = parent;
        for(auto ch : word){
            if(!temp->child[ch-'a'])
                temp->child[ch-'a']=new trie();
            temp = temp->child[ch-'a'];
        }
        temp->isEnd = true;
    }
    bool search2(string word,trie* parent,int j) {
        int n = word.size();
        trie* runn = parent;
        for(int i=j;i<n;i++){
            if(word[i]=='.'){
                for(int k=0;k<26;k++){
                    if(runn->child[k]){
                        if(search2(word,runn->child[k],i+1)) return true;
                    }
                }
                return false;
            }
            else{
                if(!runn->child[word[i]-'a']) return false;
                runn = runn->child[word[i]-'a'];
            }
        }
        return runn->isEnd;
    }
    
    bool search(string word) {
        // return true;
        return search2(word,parent,0);
    }
};
