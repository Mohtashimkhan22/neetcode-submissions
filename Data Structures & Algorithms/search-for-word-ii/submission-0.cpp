struct trie{
    trie* child[26];
    trie(){for(int i=0;i<26;i++) child[i]=nullptr;}
    string str = "";
};
class Solution {
    trie* parent = new trie();
    void insert(string word){
        int n = word.size();
        trie* runn = parent;
        for(int i=0;i<n;i++){
            if(!runn->child[word[i]-'a'])
                runn->child[word[i]-'a'] = new trie();
            runn = runn->child[word[i]-'a'];
        }
        runn->str = word;
    }
    void dfs(vector<vector<char>>& board, vector<string>& res,trie* node,int i,int j){
        int n = board.size(),m = board[0].size();
        char ch = board[i][j];
        if(!node->child[ch-'a']) return;
        node = node->child[ch-'a'];
        if(node->str!=""){
            res.push_back(node->str);
            node->str="";
        }
        
        vector<pair<int,int>> move ={{-1,0},{0,1},{1,0},{0,-1}};
        board[i][j]='#';
        for(auto it : move){
            int nr = it.first+i;
            int nc = it.second+j;
            if(nr>=0 && nc>=0 && nr<n && nc<m && board[nr][nc]!='#'){
                dfs(board,res,node,nr,nc);
            }
        }
        board[i][j]=ch;
    }
public:
    vector<string> findWords(vector<vector<char>>& board, vector<string>& words) {
        for(auto &it : words){
            insert(it);
        }
        vector<string> res;
        int n = board.size(),m = board[0].size();
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                dfs(board,res,parent,i,j);
            }
        }
        return res;
    }
};
