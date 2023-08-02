class Solution {
public:
    vector<vector<int>> ans;
    void solve(int idx, int n, vector<int>& temp) {
        cout<<idx<<" ";
        if(idx == n) {
            ans.push_back(temp);
            return;
        }
        
        for(int i=idx; i<n; i++) {
            swap(temp[i], temp[idx]);
            solve(idx+1, n, temp);
            swap(temp[i], temp[idx]);
        }
        
    }
    vector<vector<int>> permute(vector<int>& nums) {

        solve(0,nums.size(),nums);
        
        return ans;
    }
};