class NumMatrix {
    vector<vector<long long>> presum;
public:
    NumMatrix(vector<vector<int>>& matrix) {
        int n = matrix.size();
        int m = matrix[0].size();
        presum.resize(n,vector<long long>(m,0));
        for(int i=0;i<m;i++){
            presum[0][i]=matrix[0][i];
        }
        for(int i=1;i<n;i++){
            for(int j=0;j<m;j++){
                presum[i][j]=presum[i-1][j]+matrix[i][j];
            }
        }
    }
    
    int sumRegion(int row1, int col1, int row2, int col2) {
        long long sum = 0;
        for(int j=col1;j<=col2;j++){
            sum+=presum[row2][j];
        }
        if(row1==0) return sum;
        for(int j=col1;j<=col2;j++){
            sum-=presum[row1-1][j];
        }
        return sum;
    }
};

/**
 * Your NumMatrix object will be instantiated and called as such:
 * NumMatrix* obj = new NumMatrix(matrix);
 * int param_1 = obj->sumRegion(row1,col1,row2,col2);
 */