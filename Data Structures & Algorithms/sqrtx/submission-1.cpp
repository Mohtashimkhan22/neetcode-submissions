class Solution {
public:
    int mySqrt(int x) {
        long long l=1,h=x;
        while(l<=h){
            long long mid = l+(h-l)/2;
            cout<<mid<<" ";
            if(mid*mid<=x){
                l=mid+1;
            }
            else h=mid-1;
        }
        return l-1;
    }
};