class MedianFinder {
    priority_queue<int> pq1;   // max heap
    priority_queue<int, vector<int>, greater<int>> pq2; // min heap

public:
    MedianFinder() {}

    void addNum(int num) {
        if (pq1.empty() || num <= pq1.top())
            pq1.push(num);
        else
            pq2.push(num);

        // Balance the heaps
        if (pq1.size() > pq2.size() + 1) {
            pq2.push(pq1.top());
            pq1.pop();
        }
        else if (pq2.size() > pq1.size()) {
            pq1.push(pq2.top());
            pq2.pop();
        }
    }

    double findMedian() {
        if (pq1.size() == pq2.size())
            return (pq1.top() + pq2.top()) / 2.0;

        return pq1.top();
    }
};