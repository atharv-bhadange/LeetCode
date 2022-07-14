class Solution
{
public:
    int longestConsecutive(vector<int> &nums)
    {
        int n = nums.size();
        unordered_set<int> st(nums.begin(), nums.end()); // put all elements on set for fast lookup
        int ans = 0;

        for (int j = 0; j < n; j++)
        {
            if (st.find(nums[j] - 1) != st.end()) // if the previous number of current number is in the set that means we have already considered it in some sequence
            {
                continue;
            }
            else // if not found that means this element can be starting point of a continuous sequence
            {
                int i = nums[j];
                int cur_ans = 1;
                while (st.find(i + 1) != st.end()) 
                {
                    cur_ans++;
                    i++;
                }
                ans = max(cur_ans, ans); // find the max length of them all
            }
        }

        return ans;
    }
};