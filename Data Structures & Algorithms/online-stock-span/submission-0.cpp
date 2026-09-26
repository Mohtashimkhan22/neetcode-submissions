class StockSpanner {
    vector<int> st;
public:
    StockSpanner() {
        
    }
    
    int next(int price) {
        st.push_back(price);
        int n = st.size();
        int i=n-1;
        while(i>=0 && st[i]<=price) i--;
        return n-i-1;
    }
};

/**
 * Your StockSpanner object will be instantiated and called as such:
 * StockSpanner* obj = new StockSpanner();
 * int param_1 = obj->next(price);
 */