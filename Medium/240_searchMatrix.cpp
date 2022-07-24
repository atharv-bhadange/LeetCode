class Solution
{
public:
    bool searchMatrix(vector<vector<int>> &matrix, int target)
    {
        int r = matrix.size() - 1;
        int u = 0;
        while (r >= 0 && u < matrix[0].size())
        {
            // cout<<r<<" "<<u<<endl;

            if (matrix[r][u] == target)
            {
                return true;
            }
            else if (matrix[r][u] < target)
            {
                u++;
            }
            else
                r--;
        }

        return false;
    }
};

// start from bottom right corner
// move up if target is less than current
// move ahead if target is greater than current