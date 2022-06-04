class Solution
{
public:
    bool isSafe(int row, int col, vector<string> &board, int n)
    {
        int r = row;
        int c = col;

        while (r >= 0 && c >= 0)
        {
            if (board[r][c] == 'Q')
                return false;
            r--;
            c--;
        }

        r = row, c = col;

        while (c >= 0)
        {
            if (board[r][c] == 'Q')
                return false;
            c--;
        }

        r = row, c = col;

        while (r < n && c >= 0)
        {
            if (board[r][c] == 'Q')
                return false;
            r++;
            c--;
        }

        return true;
    }

    void backtrack(int col, int n, vector<string> &board, vector<vector<string>> &ans)
    {
        if (col == n)
        {
            ans.push_back(board);
            return;
        }

        for (int row = 0; row < n; row++)
        {
            if (isSafe(row, col, board, n))
            {
                board[row][col] = 'Q';
                backtrack(col + 1, n, board, ans);
                board[row][col] = '.';
            }
        }
    }

    vector<vector<string>> solveNQueens(int n)
    {
        vector<vector<string>> ans;
        string s = "";
        for (int i = 0; i < n; i++)
            s += ".";
        vector<string> board(n, s);

        backtrack(0, n, board, ans);

        return ans;
    }
};