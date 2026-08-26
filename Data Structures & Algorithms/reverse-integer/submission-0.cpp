class Solution {
public:
    int reverse(int x) {
        int sign = x>0?1:-1;
        long long res=0;
        while(x){
            int dig = x%10;
            x/=10;
            res=res*10+dig;
        }
        // cout<<sign;
        // res=res*sign;
        // cout<<res;
        int ans = 0;
        if(sign==-1) ans = res<INT_MIN?0:res;
        else ans = res>INT_MAX?0:res;
        // cout<<ans;
        return ans;
    }
};
