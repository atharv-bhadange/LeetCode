class Solution {
public:
    int minMutation(string start, string end, vector<string>& bank) {
        queue<string> q;
        unordered_set<string> st;
        q.push(start);
        st.insert(start);
        int ans = 0;
        
        while(!q.empty()) {
            int qSize = q.size();
            for(int j=0; j<qSize; j++) {
                string node = q.front();
                q.pop();
                
                if(node == end)
                    return ans;
                
                for(auto& ch : "AGCT") {
                    for(int i=0; i<node.size(); i++) {
                        string neighbor = node;
                        neighbor[i] = ch;
                        
                        if(st.find(neighbor) == st.end() && find(bank.begin(), bank.end(), neighbor) != bank.end()) {
                            q.push(neighbor);
                            st.insert(neighbor);
                        }
                    }
                }
            }
            
            ans++;
        }
        
        
        return -1;
    }
};