class Solution {
public:
    string addBinary(string a, string b) {
        string res = "";
        int carry = 0;
        int i=a.size()-1,j=b.size()-1;
        while(i>=0 || j>=0){
            int sum = carry;
            if(i>=0){
                if(a[i]=='1') sum+=1;
                i--;
            }
            if(j>=0){
                if(b[j]=='1') sum+=1;
                j--;
            }

            if(sum==0){
                res+='0';
                carry = 0;
            }
            else if(sum==1){
                res+='1';
                carry = 0;
            }
            else if(sum==2){
                res+='0';
                carry = 1;
            }
            else{
                res+='1';
                carry = 1;
            }
        }
        if(carry) res+='1';
        reverse(res.begin(),res.end());
        return res;
    }
};