class MyQueue {
    stack<int> st;
public:
    MyQueue() {
        
    }
    
    void push(int x) {
        st.push(x);
    }
    
    int pop() {
        stack<int> s;
        while(!st.empty()){
            s.push(st.top());
            st.pop();
        }
        int num = s.top();
        s.pop();
        while(!s.empty()){
            st.push(s.top());
            s.pop();
        }
        return num;
    }
    
    int peek() {
        stack<int> s;
        while(!st.empty()){
            s.push(st.top());
            st.pop();
        }
        int num = s.top();
        while(!s.empty()){
            st.push(s.top());
            s.pop();
        }
        return num;
    }
    
    bool empty() {
        return st.empty();
    }
};

/**
 * Your MyQueue object will be instantiated and called as such:
 * MyQueue* obj = new MyQueue();
 * obj->push(x);
 * int param_2 = obj->pop();
 * int param_3 = obj->peek();
 * bool param_4 = obj->empty();
 */