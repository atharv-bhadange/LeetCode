class Solution
{
public:
    long long arr[100001] = {0};
    long long maximumImportance(int n, vector<vector<int>> &roads)
    {

        for (auto r : roads)
        {
            arr[r[0]]++;
            arr[r[1]]++;
        }

        sort(arr, arr + n, less<int>());
        long long ans = 0;

        for (long long i = 0; i < n; i++)
        {
            ans += (i + 1) * arr[i];
        }

        return ans;
    }
};