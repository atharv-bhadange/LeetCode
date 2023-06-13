class Solution {
public:
    long long findScore(vector<int>& nums) {
        long long ans = 0;
        int n = nums.size();
        vector<bool> marked(n);
        
        priority_queue<pair<int,int>, vector<pair<int,int>>, greater<pair<int,int>>> pq;
        for(int i=0; i<n; i++)
            pq.push({nums[i], i});
        
        while(pq.size()>0) {
            auto popped = pq.top();
            pq.pop();
            int idx = popped.second;
            if(marked[idx]) {
                continue;
            }
            // cout<<popped.first<< " " << popped.second<< endl;
            
            ans += popped.first;
            marked[idx] = 1;
            if(idx-1>=0)
                marked[idx-1] = 1;
            if(idx+1<n)
                marked[idx+1] = 1;
        
        }
        // for(auto x: marked)
        //     cout<<x<<" ";
        return ans;
    }
};