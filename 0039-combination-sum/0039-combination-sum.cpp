class Solution {
public:
    
    void solve(set<vector<int>>& ans, vector<int> ip, vector<int> op, int sum, int target) {
        if(ip.size() == 0) {
            if(sum == target) {
                ans.insert(op);
            }
            return;
        }
        if(sum==target) {
            ans.insert(op);
            return;
        }
        int curr = ip[0];
        if(sum + curr <= target) {
            op.push_back(curr);
            solve(ans, ip, op, sum+curr, target);
            ip.erase(ip.begin());
            solve(ans, ip, op, sum+curr, target);
            op.pop_back();
            solve(ans, ip, op, sum, target);
        }
        else {
            ip.erase(ip.begin());
            solve(ans, ip, op, sum, target);
        }
    }
    
    vector<vector<int>> combinationSum(vector<int>& candidates, int target) {
        set<vector<int>> t;
        vector<int> op;
        solve(t, candidates, op, 0, target);
        vector<vector<int>> ans(t.begin(),t.end());
        return ans;
    }
};