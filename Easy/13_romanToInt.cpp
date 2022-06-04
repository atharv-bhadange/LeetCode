class Solution
{
public:
    int romanToInt(string s)
    {
        map<char, int> m;
        m.insert({'I', 1});
        m.insert({'V', 5});
        m.insert({'X', 10});
        m.insert({'L', 50});
        m.insert({'C', 100});
        m.insert({'D', 500});
        m.insert({'M', 1000});

        int n = s.size();
        int ans = 0;
        if (n == 1)
            return m[s[0]];
        for (int i = 0; i < n - 1; i++)
        {
            if (m[s[i]] < m[s[i + 1]])
            {
                ans += m[s[i + 1]] - m[s[i]];
                i++;
            }
            else
                ans += m[s[i]];
            // cout << ans << endl;
        }

        if (m[s[n - 2]] >= m[s[n - 1]])
            ans += m[s[n - 1]];

        return ans;
    }
};