struct trie{
    trie* child[26];

    trie() {
        for(int i=0;i<26;i++)
            child[i]=nullptr;
    }

    bool isEnd=false;
};

class PrefixTree {
    trie* parent;
public:
    PrefixTree() {
        parent = new trie();
    }
    
    void insert(string word) {
        int n = word.size();
        trie* runn = parent;
        for(int i=0;i<n;i++){
            if(!runn->child[word[i]-'a'])
                runn->child[word[i]-'a'] = new trie();
            runn = runn->child[word[i]-'a'];
        }
        runn->isEnd = true;
    }
    
    bool search(string word) {
        int n = word.size();
        trie* runn = parent;
        for(int i=0;i<n;i++){
            if(!runn->child[word[i]-'a']) return false;
            runn = runn->child[word[i]-'a'];
        }
        return runn->isEnd;
    }
    
    bool startsWith(string prefix) {
        int n = prefix.size();
        trie* runn = parent;
        for(int i=0;i<n;i++){
            if(!runn->child[prefix[i]-'a']) return false;
            runn = runn->child[prefix[i]-'a'];
        }
        return true;
    }
};
