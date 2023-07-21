class Solution {
public:
    vector<int> maxSlidingWindow(vector<int>& a, int k) {
        if(k==1)
            return a;
        int i = 0, j = 0;
        list<int> q;
        int n = a.size();
        vector<int> ans;
        while(j<n) {
            // for(auto& x: q) 
            //     cout<<x<<"+ ";
            while(!q.empty() && q.back() < a[j]) {
                    q.pop_back();
                // cout<<a[j]<<"* ";
            }
            // cout<<endl;
            q.push_back(a[j]);
            if(j-i+1 != k) {
                j++;
            }
            else if(j-i+1 == k) {
                ans.push_back(q.front());

                if(a[i] == q.front()) {
                    q.pop_front();
                }
                i++;
                j++;
            }
            // for(auto& x: q) 
            //     cout<<x<<"* ";
        }
        
        return ans;
    }
};