class Solution
{
    vector<vector<int>> ans;

public:
    void recur(int n, int k, vector<int> &sub, int num)
    {
        if (k == 0)
        {
            if (accumulate(sub.begin(), sub.end(), 0) == n)
            {
                ans.push_back(sub);
                // sub.clear();
            }
            return;
        }
        if (num > 9)
        {
            return;
        }
        sub.push_back(num);
        recur(n, k - 1, sub, num + 1);
        sub.pop_back();
        recur(n, k, sub, num + 1);
    }
    vector<vector<int>> combinationSum3(int k, int n)
    {
        vector<int> sub;
        recur(n, k, sub, 1);
        return ans;
    }
};