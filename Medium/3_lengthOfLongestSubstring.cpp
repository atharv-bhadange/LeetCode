class Solution
{
public:
    int lengthOfLongestSubstring(string s)
    {
        if (s.size() <= 1)
            return s.size();

        int ans = INT_MIN;
        map<char, int> m;
        for (int i = 0, j = 0; i < s.size(); i++)
        {
            if (m.find(s[i]) != m.end())
            {
                j = max(j, m[s[i]] + 1);
            }
            m[s[i]] = i;
            ans = max(ans, i - j + 1);
        }

        return ans;
    }
};
