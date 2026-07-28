class Solution {
    bool isSafe(vector<string> &board,int row,int col,int n){
        // check row
        for(int i=0;i<n;i++){
            if(board[row][i]!='.') return false;
        }
        // check col
        for(int i=0;i<n;i++){
            if(board[i][col]!='.') return false;
        }
        // check diagonal1
        int i=row,j=col;
        while(i>=0 && j<n){
            if(board[i][j]!='.') return false;
            i--;
            j++;
        }
        i=row,j=col;
        while(j>=0 && i<n){
            if(board[i][j]!='.') return false;
            i++;
            j--;
        }
        // check diagonal2
        i=row,j=col;
        while(i>=0 && j>=0){
            if(board[i][j]!='.') return false;
            i--;
            j--;
        }
        i=row,j=col;
        while(j<n && i<n){
            if(board[i][j]!='.') return false;
            i++;
            j++;
        }
        return true;
    }
    void solver(vector<vector<string>> &res,vector<string> &board,int col,int n){
        if(col==n){
          res.push_back(board);
          return;
        }
        for(int row=0;row<n;row++){
            if(isSafe(board,row,col,n)){
                board[row][col]='Q';
                solver(res,board,col+1,n);
                board[row][col]='.';
            }
        }
    }
public:
    vector<vector<string>> solveNQueens(int n) {
        if(n==1) return {{"Q"}};
        string str="";
        for(int i=0;i<n;i++){
            str+=".";
        }
        vector<vector<string>> res;
        vector<string> board(n,str);
        solver(res,board,0,n);
        return res;
    }
};
