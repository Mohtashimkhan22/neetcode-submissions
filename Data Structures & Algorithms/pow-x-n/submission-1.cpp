class Solution {
public:
    double myPow(double x, int n) {
        if(n==0) return 1;
        if(x==1 || n==1) return x;
        if(n<0){
            x=1/x;
            n=-n;
        }
        double prod=1.0;
        double curr = x;
        for(int i=n;i>0;i/=2){
            if(i%2==1) prod*=curr;
            curr*=curr;
        }
        return prod;
    }
};
