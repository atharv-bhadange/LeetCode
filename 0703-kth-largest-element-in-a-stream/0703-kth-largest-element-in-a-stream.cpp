class KthLargest {
public:
    int k;
    vector<int> nums;
    priority_queue<int, vector<int>, greater<int>> pq;
    KthLargest(int k, vector<int>& nums) {
        this->k = k;
        this->nums = nums;
        
        for(int i=0; i<nums.size(); i++) {
            pq.push(nums[i]);
            if(pq.size() > k)
                pq.pop();
        }
    }
    
    int add(int val) {
        nums.push_back(val);
        cout<<pq.size();
        pq.push(val);
        if(pq.size() > k)
            pq.pop();
        int x = pq.top();
        
        return x;
    }
};

/**
 * Your KthLargest object will be instantiated and called as such:
 * KthLargest* obj = new KthLargest(k, nums);
 * int param_1 = obj->add(val);
 */