class Solution {
public:
    vector<int> getOrder(vector<vector<int>>& tasks) {
        priority_queue<pair<int,int>, vector<pair<int,int>>, greater<>> pq;
        vector<vector<int>> sortedArray;
        for(int i=0; i<tasks.size(); i++) {
            sortedArray.push_back({tasks[i][0],tasks[i][1],i});
        }
        sort(sortedArray.begin(),sortedArray.end());
        int taskIdx = 0;
        long long currTime = 0;
        vector<int> ans;
        while(!pq.empty() || taskIdx<tasks.size()) {
            if(pq.empty() && currTime < sortedArray[taskIdx][0]) {
                currTime = sortedArray[taskIdx][0];
            }
            while(taskIdx < sortedArray.size() && currTime >= sortedArray[taskIdx][0]) {
                pq.push({sortedArray[taskIdx][1], sortedArray[taskIdx][2]});
                taskIdx++;
            }
            
            auto [processTime, idx] = pq.top();
            pq.pop();
            currTime += processTime;
            ans.push_back(idx);
        }
        
        return ans;
    }
};