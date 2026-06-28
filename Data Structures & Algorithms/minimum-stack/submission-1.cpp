class MinStack {
    stack<int> st;
    stack<int> mini;
public:
    MinStack() {
        
    }
    
    void push(int val) {
        st.push(val);
        if(mini.empty()) mini.push(val);
        else{
            if(mini.top()>=val){
                mini.push(val);
            }
            
        }
    }
    
    void pop() {
        int num = st.top();
        st.pop();
        if(num==mini.top()){
            mini.pop();
        }
    }
    
    int top() {
        return st.top();   
    }
    
    int getMin() {
        return mini.top();
    }
};
