class Solution
{
public:
    string reverseStr(string s, int k)
    {
        int n = s.size();
        if (n <= k)
        {
            reverse(s.begin(), s.end());
            return s;
        }
        int i = 0;
        for (i = 0; (i + k) < n; i += 2 * k)
        {
            // if(i<n)
            reverse(s.begin() + i, s.begin() + i + k);
            // cout<<i<<" ";
        }
        if (n - i <= k)
            reverse(s.begin() + i, s.end());
        if (n - i > k && n - i < 2 * k)
            reverse(s.begin() + i, s.begin() + i + k);

        return s;
    }
};