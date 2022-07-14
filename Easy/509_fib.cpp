class Solution
{
public:
    int fib(int n)
    {
        if (n == 0)
            return 0;
        if (n == 1)
            return 1;
        return fib(n - 1) + fib(n - 2);
    }

    int fibI(int n)
    {
        int a[n + 1];
        a[0] = 0;
        a[1] = 1;
        for (int i = 2; i <= n; i++)
            a[i] = a[i - 1] + a[i - 2];

        int output = a[n];
        return output;
    }
};
