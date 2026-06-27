class Solution {
public:
    bool isValidSudoku(vector<vector<char>>& board) {
        unordered_set<string> str;
        for(int i=0;i<9;i++){
            for(int j=0;j<9;j++){
                if(board[i][j]=='.') continue;
                char c = board[i][j];
                string s1 = string(1,c) + "present in row " + to_string(i);
                string s2 = string(1,c) + "present in col " + to_string(j);
                string s3 = string(1,c) + "present in box " + to_string(i/3) + to_string(j/3);
                if(str.count(s1)) return false;
                if(str.count(s2)) return false;
                if(str.count(s3)) return false;
                str.insert(s1);
                str.insert(s2);
                str.insert(s3);
            }
        }
        return true;
    }
};
