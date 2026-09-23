class Solution {
public:
    int calPoints(vector<string>& operations) {
        stack<int> st;
        for(int i=0;i<operations.size();i++){
            if(operations[i]=="D"){
                int num = st.top();
                st.push(num*2);
            }
            else if(operations[i]=="C"){
                st.pop();
            }
            else if(operations[i]=="+"){
                int num1 = st.top();
                st.pop();
                int num2 = st.top();
                st.pop();
                st.push(num2);
                st.push(num1);
                st.push(num1+num2);
            }
            else{
                int num = stoi(operations[i]);
                st.push(num);
            }
        }
        int sum = 0;
        while(!st.empty()){
            sum+=st.top();
            st.pop();
        }
        return sum;
    }
};