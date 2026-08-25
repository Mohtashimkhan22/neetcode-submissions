class Solution {
public:
    vector<int> spiralOrder(vector<vector<int>>& matrix) {
        int n = matrix.size();
        int m = matrix[0].size();
        int right=m-1,left=0;
        int down=n-1,up=0;
        vector<int> res;
        while(left<=right && up<=down){
            for(int i=left;i<=right;i++){
                res.push_back(matrix[up][i]);
            }
            up++;
            for(int i=up;i<=down;i++){
                res.push_back(matrix[i][right]);
            }
            right--;
            if(left<=right && up<=down){
                for(int i=right;i>=left;i--){
                    res.push_back(matrix[down][i]);
                }
                down--;
                for(int i=down;i>=up;i--){
                    res.push_back(matrix[i][left]);
                }
                left++;
            }
        }
        return res;
    }
};
