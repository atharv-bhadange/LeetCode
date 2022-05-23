class Solution
{
public:
    bool find132pattern(vector<int> &nums)
    {
        stack<int> st;
        int mid = INT_MIN;
        for (int i = nums.size() - 1; i >= 0; i--)
        {
            if (mid > nums[i])
                return true;

            while (!st.empty() && nums[i] > st.top())
            {
                mid = st.top();
                st.pop();
            }
            st.push(nums[i]);
        }

        return false;
    }
};