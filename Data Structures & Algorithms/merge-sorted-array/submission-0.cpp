class Solution {
public:
    void merge(vector<int>& num1, int m, vector<int>& num2, int n) {
        int i=m-1,j=n-1,k=(m+n-1);
        while(k>=0){
            if(i<0) num1[k--]=num2[j--];
            else if(j<0) num1[k--]=num1[i--];
            else if(num1[i]>=num2[j]){
                num1[k]=num1[i];
                k--;
                i--;
            }
            else{
                num1[k]=num2[j];
                k--;
                j--;
            }
        }
    }
};