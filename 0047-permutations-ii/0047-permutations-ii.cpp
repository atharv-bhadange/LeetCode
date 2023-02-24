class Solution {
public:
    vector<vector<int>> permuteUnique(vector<int>& nums) {
        int n = nums.size()-1;
        set<vector<int>> ans;
        auto temp = nums;
        do
        {
            next_permutation(temp.begin(),temp.end());
            ans.insert(temp);
        }
        while(temp!=nums);
        vector<vector<int>> v;
        for(auto x: ans) v.push_back(x);
        return v;
    }
};