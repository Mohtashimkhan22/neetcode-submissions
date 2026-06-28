class Solution {
public:
    bool isValid(string s) {
        stack<char> st;
        int i=0;
        while(i<s.size()){
            char ch = s[i];
            if(st.empty() || ch=='(' || ch=='{' || ch=='['){
                st.push(ch);
            }
            else{
                if(ch==')' && st.top()=='(') st.pop();
                else if(ch=='}' && st.top()=='{') st.pop();
                else if(ch==']' && st.top()=='[') st.pop();
                else return false;
            }
            i++;
        }
        return st.empty();
    }
};
