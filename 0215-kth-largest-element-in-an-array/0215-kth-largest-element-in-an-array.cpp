class Solution {
public:
    int findKthLargest(vector<int>& a, int k) {
        int ans = 0;
        int n = a.size();
        priority_queue<int, vector<int>, greater<int>> pq;

        for(int i=0; i<n; i++) {
            pq.push(a[i]);

            if(pq.size() > k) {
                pq.pop();
            }
        }

        return ans = pq.top();
    }
};