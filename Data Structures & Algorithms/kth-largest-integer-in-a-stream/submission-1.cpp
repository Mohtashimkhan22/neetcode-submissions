class KthLargest {
    priority_queue<int,vector<int>, greater<int>> pq;
    int n;
public:
    KthLargest(int k, vector<int>& nums) {
        n=k;
        for(int num : nums){
            pq.push(num);
        }
        while(pq.size()>k) pq.pop();
    }
    
    int add(int val) {
        
        pq.push(val);
        while(pq.size()>n) pq.pop();
        return pq.top();
    }
};
