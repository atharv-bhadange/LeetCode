class Solution
{
public:
    string removeDuplicates(string s, int k)
    {
        int n = s.size();
        if (n < k)
            return s;
        stack<pair<char, int>> st;

        for (int i = 0; i < n; i++)
        {
            if (st.empty() || st.top().first != s[i])
                st.push({s[i], 1});
            else
            {
                auto pi = st.top();
                int p = pi.second;
                st.pop();
                st.push({s[i], p + 1});
            }
            if (st.top().second == k)
                st.pop();
        }

        string ans;
        while (!st.empty())
        {
            auto p = st.top();
            char ch = p.first;
            while (p.second--)
                ans.push_back(ch);
            st.pop();
        }
        reverse(ans.begin(), ans.end());
        return ans;
    }
};

// Stack used to store a pair of character and its frequency.
// If the frequency of the character is less than k, we push it into the stack.
// If the frequency of the character is equal to k, we pop it out and push the next character into the stack.

// Alternative solution:

class Solution
{
public:
    string removeDuplicates(string s, int k)
    {
        int j = 0;
        vector<int> cnt(s.size(), 1);
        for (auto i = 0; i < s.size(); ++i, ++j)
        {
            s[j] = s[i];
            if (j > 0 && s[j] == s[j - 1])
                cnt[j] = cnt[j - 1] + 1;
            else
                cnt[j] = 1;
            if (cnt[j] == k)
                j -= k;
        }
        return s.substr(0, j);
    }
};

// Storing the frequency of each character in a vector.
