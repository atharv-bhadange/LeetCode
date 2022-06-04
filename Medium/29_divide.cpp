class Solution
{
public:
    int divide(int dividend, int divisor)
    {
        // return dividend/divisor;
        if (dividend == INT_MIN and divisor == -1)
            return INT_MAX;
        if (dividend == INT_MIN and divisor == 1)
            return INT_MIN;

        long int d = abs(dividend);
        long int v = abs(divisor);

        int cnt = 0;
        while (v <= d)
        {
            long int mul = v;
            int t = 1;
            while (mul <= d - mul)
            {
                mul += mul;
                t += t;
            }
            cnt += t;
            d -= mul;
        }

        if ((dividend < 0 && divisor > 0) || (dividend > 0 && divisor < 0))
            return -cnt;

        return cnt;
    }
};