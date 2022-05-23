class Solution
{
public:
    int countSubstrings(string s)
    {
        int ans = 0;
        int n = s.size();
        // if(n==1) return 1;
        int l = 0, r = s.size() - 1;
        for (int i = 0; i < n; i++)
        {

            l = r = i;
            while (l >= 0 && r < n && s[l--] == s[r++])
                ans++;

            l = i - 1, r = i;
            while (l >= 0 && r < n && s[l--] == s[r++])
                ans++;
        }

        return ans;
    }
};