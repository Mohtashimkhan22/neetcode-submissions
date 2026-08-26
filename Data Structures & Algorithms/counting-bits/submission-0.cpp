class Solution {
public:
    vector<int> countBits(int n) {
        vector<int> res(n+1,0);
        while(n){
            int num = n;
            int count = 0;
            while(num){
                count+=num&1;
                num>>=1;
            }
            res[n]=count;
            n--;
        }
        return res;
    }
};
