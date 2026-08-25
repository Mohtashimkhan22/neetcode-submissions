class Solution {
public:
    void setZeroes(vector<vector<int>>& matrix) {
        int n = matrix.size();
        int m = matrix[0].size();
        bool zeroRow = false,zeroCol=false;
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                if(matrix[i][j]==0){
                    if (j==0) zeroCol = true;
                    else matrix[0][j] = 0;
                    if(i==0) zeroRow=true;
                    else matrix[i][0]=0;
                }
            }
        }
        // for(int i=0;i<n;i++){
        //     for(int j=0;j<m;j++){
        //         cout<<matrix[i][j]<<" ";
        //     }
        //     cout<<endl;
        // }
        for(int j=m-1;j>0;j--){
            if(matrix[0][j]==0){
                for(int i=0;i<n;i++){
                    matrix[i][j]=0;
                }
            }
            
        }
        for(int i=n-1;i>0;i--){
            if(matrix[i][0]==0){
                for(int j=0;j<m;j++){
                    matrix[i][j]=0;
                }
            }
            
        }
        if(zeroRow){
           for(int j=0;j<m;j++){
                matrix[0][j]=0;
            } 
        }
        if(zeroCol){
           for(int j=0;j<n;j++){
                matrix[j][0]=0;
            } 
        }
        return;
    }
};
