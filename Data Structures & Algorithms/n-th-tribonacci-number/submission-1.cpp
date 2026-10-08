class Solution {
public:
    int tribonacci(int n) {
        if(n==0) return 0;
        if(n==1) return 1;
        if(n==2) return 1;
        int t0 = 0, t1 = 1, t2 = 1;
        int i=3;
        while(i<=n){
            int t3 = t0+t1+t2;
            t0=t1;
            t1=t2;
            t2=t3;
            i++;
        }
        return t2;
    }
};