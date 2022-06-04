class NumMatrix
{
    // vector<vector<int>> mtx;
    vector<vector<int>> ans;

public:
    NumMatrix(vector<vector<int>> &mtx)
    {
        int m = mtx.size();
        int n = mtx[0].size();
        ans = vector<vector<int>>(m + 1, vector<int>(n + 1, 0));
        for (int i = 0; i < m; i++)
            for (int j = 0; j < n; j++)
                ans[i + 1][j + 1] += mtx[i][j] + ans[i + 1][j] + ans[i][j + 1] - ans[i][j];
    }

    int sumRegion(int row1, int col1, int row2, int col2)
    {
        int a = ans[row2 + 1][col2 + 1] - ans[row2 + 1][col1] - ans[row1][col2 + 1] + ans[row1][col1];

        return a;
    }
};

/**
 * Your NumMatrix object will be instantiated and called as such:
 * NumMatrix* obj = new NumMatrix(matrix);
 * int param_1 = obj->sumRegion(row1,col1,row2,col2);
 */

// two solution possible for this question
// one is by considering matrix as n 1D arrays and storing the prefix sum
// other is by considering the sum of the area by subtracting the overlapping part better explained in the solution part

// row caching
/*
class NumMatrix {
    // vector<vector<int>> mtx;
    vector<vector<int>> ans;
public:
    NumMatrix(vector<vector<int>>& mtx) {
        int m = mtx.size();
        int n = mtx[0].size();
        ans = vector<vector<int>> (m, vector<int> (n+1, 0));
        for(int i=0; i<m; i++)
            for(int j=0; j<n; j++)
                ans[i][j+1]+=mtx[i][j] + ans[i][j];
    }

    int sumRegion(int row1, int col1, int row2, int col2) {
        int a = 0;

        for(int i=row1; i<=row2; i++)
            a+=ans[i][col2+1] - ans[i][col1];
        return a;
    }
};

 * Your NumMatrix object will be instantiated and called as such:
 * NumMatrix* obj = new NumMatrix(matrix);
 * int param_1 = obj->sumRegion(row1,col1,row2,col2);

*/