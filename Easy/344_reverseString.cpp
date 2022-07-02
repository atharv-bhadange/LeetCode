class Solution
{
public:
    void recur(int l, int r, vector<char> &s)
    {
        if (l >= r)
            return;
        swap(s[l], s[r]);
        recur(++l, --r, s);
    }

    void reverseString(vector<char> &s)
    {
        int n = s.size();
        // recur(0,n-1,s);
        for (int i = 0; i < n / 2; i++)
            swap(s[i], s[n - i - 1]);

        // return s;
    }
};