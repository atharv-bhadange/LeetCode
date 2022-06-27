class Solution
{
public:
    int minPartitions(string n)
    {
        int k = -1;
        for (int i = 0; i < n.size(); i++)
        {
            k = max(k, n[i] - '0');
        }

        return k;
    }
};

// this question must go in easy
// ofc the max single digit in the string is the answer