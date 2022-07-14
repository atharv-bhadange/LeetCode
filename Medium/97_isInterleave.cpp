class Solution
{
public:
    bool recur(string s1, string s2, string s3, int i, int j, int k, vector<vector<int>> &t)
    {
        if (i == -1)
            return s2.substr(0, j + 1) == s3.substr(0, k + 1);
        // cout<<s1.substr(0,i)<<endl;
        if (j == -1)
            return s1.substr(0, i + 1) == s3.substr(0, k + 1);

        if (i >= 0 && j >= 0 && t[i][j] != -1)
        {
            return t[i][j];
        }

        bool left = false;
        if (i >= 0 && s1[i] == s3[k])
            left = recur(s1, s2, s3, i - 1, j, k - 1, t);

        bool right = false;
        if (j >= 0 && s2[j] == s3[k])
            right = recur(s1, s2, s3, i, j - 1, k - 1, t);

        if (i >= 0 && j >= 0)
            t[i][j] = left || right;
        return left || right;
    }

    bool isInterleave(string s1, string s2, string s3)
    {
        int i = s1.size();
        int j = s2.size();
        int k = s3.size();

        if (i + j != k)
            return false;

        vector<vector<int>> t(i + 1, vector<int>(j + 1, -1));

        // memset(t, -1, sizeof(t));

        return recur(s1, s2, s3, i - 1, j - 1, k - 1, t);
    }
};

// initial approach was of 3D dp storing i j k
// then 2D dp approach is of comparing the substrings till ith and jth character