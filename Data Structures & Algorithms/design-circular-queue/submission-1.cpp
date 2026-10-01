class MyCircularQueue {
    vector<int> q;
    int k,f,r;
    int cnt;
public:
    MyCircularQueue(int k) {
        q.resize(k);
        this->k=k;
        f=0;
        r=0;
        cnt=0;
    }
    
    bool enQueue(int value) {
        if(isFull()) return false;
        q[r%k]=value;
        r++;
        cnt++;
        return true;
    }
    
    bool deQueue() {
        if(isEmpty()) return false;
        f++;
        cnt--;
        return true;
    }
    
    int Front() {
        if(isEmpty()) return -1;
        return q[f%k];
    }
    
    int Rear() {
        if(isEmpty()) return -1;
        return q[(r-1)%k];
    }
    
    bool isEmpty() {
        return cnt==0;
    }
    
    bool isFull() {
        return cnt==k;
    }
};

/**
 * Your MyCircularQueue object will be instantiated and called as such:
 * MyCircularQueue* obj = new MyCircularQueue(k);
 * bool param_1 = obj->enQueue(value);
 * bool param_2 = obj->deQueue();
 * int param_3 = obj->Front();
 * int param_4 = obj->Rear();
 * bool param_5 = obj->isEmpty();
 * bool param_6 = obj->isFull();
 */