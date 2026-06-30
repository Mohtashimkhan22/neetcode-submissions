class Solution {
public:
    bool searchMatrix(vector<vector<int>>& matrix, int target) {
        int n = matrix.size();
        int m = matrix[0].size();
        int l=0;
        int h=n*m-1;
        while(l<=h){
            int mid = (l+h)/2;
            int c = mid%m;
            int r = mid/m;
            // cout<<r<<" "<<c<<endl;
            if(matrix[r][c]==target) return true;
            else if(matrix[r][c]>target) h=mid-1;
            else l=mid+1;
        }
        return false;
    }
};
