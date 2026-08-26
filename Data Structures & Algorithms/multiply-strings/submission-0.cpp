class Solution {
    string add(string a, string b) {
        int i = a.size() - 1;
        int j = b.size() - 1;
        int carry = 0;
        string ans = "";

        while(i >= 0 || j >= 0 || carry) {
            int sum = carry;

            if(i >= 0) sum += a[i--] - '0';
            if(j >= 0) sum += b[j--] - '0';

            ans += to_string(sum % 10);
            carry = sum / 10;
        }

        reverse(ans.begin(), ans.end());
        return ans;
    }
public:
    string multiply(string num1, string num2) {
        if(num1[0]=='0' || num2[0]=='0') return "0";
        int n = num1.size();
        int m = num2.size();
        vector<string> str(n);
        for(int i=n-1;i>=0;i--){
            string temp = "";
            int carry = 0;
            for(int j=m-1;j>=0;j--){
                int dig = (num2[j]-'0')*(num1[i]-'0')+carry;
                carry = dig/10;
                dig=dig%10;
                temp+=to_string(dig);
            }
            if(carry) temp+=to_string(carry);
            reverse(temp.begin(),temp.end());
            str[i]=temp;
            cout<<temp<<" ";
        }
        string st = "";
        for(int i=n-1;i>=0;i--){
            str[i]+=st;
            st+="0";
        }
        string ans = "0";

        for(int i=0; i<n; i++){
            ans = add(ans, str[i]);
        }

        return ans;
    }
};
