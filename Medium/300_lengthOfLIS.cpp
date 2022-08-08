class Solution
{
public:
    int recur(vector<int> &nums, int last, int n, vector<int> &dp)
    {
        if (n == 0)
            return 0;
        if (dp[last + 1] != -1)
            return dp[last + 1];
        int ans = 0;
        int ans2 = recur(nums, last, n - 1, dp); // without considering current 
        if (last == -1 || nums[n - 1] < nums[last])
        {
            ans = 1 + recur(nums, n - 1, n - 1, dp); // with considering current if condition satisfies
        }

        return dp[last + 1] = max(ans, ans2);
    }
    int lengthOfLIS(vector<int> &nums)
    {
        vector<int> dp(nums.size() + 1, -1);
        return recur(nums, -1, nums.size(), dp);
    }
}; // figured out on my own but slow solution



// not so intuitive solution 
// create a new subsequence if the current element cannot be added to any existing list

class Solution {
public:
    int lengthOfLIS(vector<int>& nums) {
        int l = 0;
        for(auto &x : nums) //sublisting
        {
            if(l==0 || nums[l-1]<x) nums[l++] = x;
            else
                *lower_bound(nums.begin(),nums.begin()+l,x) = x; // new list is created within the current list
        }
        return l;
    }
};