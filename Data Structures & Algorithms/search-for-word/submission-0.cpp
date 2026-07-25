class Solution {
    bool solver(vector<vector<char>>& board, string &word,string curr,int i,int j){
        if(word==curr) return true;
        int n = board.size();
        int m = board[0].size();
        vector<pair<int,int>> move = {{-1,0},{0,1},{1,0},{0,-1}};
        for(auto it : move){
            int r = i+it.first;
            int c = j+it.second;
            if(r>=0 && r<n && c>=0 && c<m && word[curr.size()]==board[r][c]){
                string str = curr;
                char ch = board[r][c];
                curr+=ch;
                board[r][c]='#';
                cout<<curr<<" ";
                if(solver(board,word,curr,r,c)) return true;
                curr=str;
                board[r][c]=ch;
            }
        }
        return false;
    }
public:
    bool exist(vector<vector<char>>& board, string word) {
        string curr = "";
        int n = board.size();
        int m = board[0].size();
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                if(board[i][j]==word[0]){
                    curr+=word[0];
                    board[i][j]='#';
                    if(solver(board,word,curr,i,j)) return true;
                    board[i][j]=word[0];
                    curr="";
                }
            }
        }
        return false;
    }
};
