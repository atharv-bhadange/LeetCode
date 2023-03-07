class Solution {
public:
    void backtrack(vector<int>& candi, vector<int>& curComb, vector<vector<int>>& ans, int target, int curSum, int idx) {
        if(curSum>target) return;
        if(curSum==target){
            ans.push_back(curComb);
            return;
        }
        
        for(int i=idx; i<candi.size(); i++)
        {
            if(i>idx && candi[i] == candi[i-1])
                continue;
            
            curSum+=candi[i];
            curComb.push_back(candi[i]);
            backtrack(candi, curComb, ans, target, curSum, i+1);
            curSum-=candi[i];
            curComb.pop_back();
        }
    }
    
    vector<vector<int>> combinationSum2(vector<int>& candidates, int target) {
        vector<int> curComb;
        vector<vector<int>> ans;
        sort(candidates.begin(), candidates.end()); //good move
        backtrack(candidates, curComb, ans, target, 0,0);
        
        return ans;
    }
};