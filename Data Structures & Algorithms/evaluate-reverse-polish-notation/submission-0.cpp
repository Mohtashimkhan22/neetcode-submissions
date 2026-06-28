class Solution {
public:
    int evalRPN(vector<string>& tokens) {
        stack<int> st;
        for(auto it : tokens){
            
            if(it=="+" || it=="-" || it=="*" || it=="/"){
                int num1 = st.top();
                st.pop();
                int num2 = st.top();
                st.pop();
                int res;
                if(it=="+") res = num2+num1;
                if(it=="-") res = num2-num1;
                if(it=="*") res = num2*num1;
                if(it=="/") res = num2/num1;
                st.push(res);
                cout<<res<<" ";
            }
            else{
                st.push(stoi(it));
            }
        }
        return st.top();
    }
};
