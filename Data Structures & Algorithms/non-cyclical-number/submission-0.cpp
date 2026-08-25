class Solution {
public:
    bool isHappy(int n) {
        unordered_set<int> st;
        st.insert(n);
        int sum=n,num=n;
        while(sum!=1){
            sum=0;
            while(num){
                int dig  = num%10;
                num/=10;
                sum+=(dig*dig);
            }
            // cout<<sum<<" ";
            num=sum;
            if(st.count(num)) return false;
            st.insert(num);
        }
        return true;
    }
};
