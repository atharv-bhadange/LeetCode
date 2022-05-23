class Solution
{
public:
    void setZeroes(vector<vector<int>> &matrix)
    {
        int m = matrix.size();
        int n = matrix[0].size();
        vector<int> ik, jk;
        for (int i = 0; i < m; i++)
        {
            for (int j = 0; j < n; j++)
            {
                if (matrix[i][j] == 0)
                {
                    ik.push_back(i);
                    jk.push_back(j);
                }
            }
        }
        for (int i = 0; i < ik.size(); i++)
        {
            for (int j = 0; j < n; j++)
            {
                matrix[ik[i]][j] = 0;
            }
        }

        for (int i = 0; i < jk.size(); i++)
        {
            for (int j = 0; j < m; j++)
            {
                matrix[j][jk[i]] = 0;
            }
        }
    }
};

// optimized solution is to use the first row and first column to store the information of whether the first row and first column is 0.