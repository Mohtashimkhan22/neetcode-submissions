class FreqStack {
    vector<int> st;
    unordered_map<int,int> mp;
    priority_queue<pair<int,int>> pq;
public:
    FreqStack() {
        
    }
    
    void push(int val) {
        mp[val]++;
        st.push_back(val);
    }
    
    int pop() {
        int ind = 0;
        int num = -1;
        for(int i=0;i<st.size();i++){
            if(mp[st[i]]>=mp[st[ind]]){
                ind=i;
                num = st[i];
            }
        }
        mp[st[ind]]--;
        st.erase(st.begin()+ind);
        return num;
    }
};

/**
 * Your FreqStack object will be instantiated and called as such:
 * FreqStack* obj = new FreqStack();
 * obj->push(val);
 * int param_2 = obj->pop();
 */