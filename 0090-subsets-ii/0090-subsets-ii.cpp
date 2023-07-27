class Solution {
public:
    set<vector<int>> tmp;
    void solve(vector<int> ip, vector<int> op) {
        if(ip.size() == 0) {
            sort(op.begin(),op.end());
            tmp.insert(op);
            return;
        }
        // vector<int> op1 = op;
        vector<int> op2 = op;
        op2.push_back(ip[0]);
        
        ip.erase(ip.begin());
        
        solve(ip,op);
        solve(ip,op2);
    }
    vector<vector<int>> subsetsWithDup(vector<int>& nums) {
        vector<int> temp;
        solve(nums,temp);
        vector<vector<int>> ans(tmp.begin(),tmp.end());
        return ans;
    }
};