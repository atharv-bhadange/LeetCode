class Solution
{
public:
    int NcR(int n, int r)
    {
        int p = 1, k = 1;

        if (n - r < r)
            r = n - r;

        if (r != 0)
        {
            while (r)
            {
                p *= n;
                k *= r;

                int m = __gcd(p, k);

                p /= m;
                k /= m;

                n--;
                r--;
            }
        }

        else
            p = 1;
        return p;
    }

    int countVowelStrings(int r)
    {
        int n = 5;
        return NcR(n + r - 1, r);
    }
};