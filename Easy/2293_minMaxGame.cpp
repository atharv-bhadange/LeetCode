class Solution
{
public:
    int minMaxGame(vector<int> &a)
    {
        int n = a.size();
        for (int i = n; i > 1; i /= 2)
        {
            for (int j = 0; j < i / 2; j++)
                a[j] = j % 2 == 0 ? min(a[j * 2], a[j * 2 + 1]) : max(a[j * 2], a[j * 2 + 1]);
        }

        return a[0];
    }
};