class MedianFinder {
public:
    priority_queue<int> decre;
    priority_queue<int, vector<int>, greater<int>> incre;
    bool even = true;
    MedianFinder() {
    }
    
    void addNum(int num) {
        even = !even;
        if(!even) {
            decre.push(num);
            incre.push(decre.top());
            decre.pop();
        } else {
            incre.push(num);
            decre.push(incre.top());
            incre.pop();
        }        
    }
    
    double findMedian() {
        if(even)
            return (incre.top()+decre.top())/2.0;
        else
            return incre.top();
    }
};

/**
 * Your MedianFinder object will be instantiated and called as such:
 * MedianFinder* obj = new MedianFinder();
 * obj->addNum(num);
 * double param_2 = obj->findMedian();
 */