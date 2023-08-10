class Solution {
public:
    
    bool check(vector<vector<char>>& board, int x, int y, char rep) {
        for(int i=0; i<9; i++) 
            if(board[i][y] == rep)
                return 0;
        
        for(int j=0; j<9; j++) 
            if(board[x][j] == rep)
                return 0;
            
        int m = x - x%3, n = y - y%3;
        
        for(int i=0; i<3; i++) {
            for(int j=0; j<3; j++) {
                if(board[i+m][j+n] == rep)
                    return 0;
            }
        }
        
        return 1;
    }
    
    bool solve(vector<vector<char>>& board, int i, int j) {
        if(i==9) 
            return 1;
        if(j==9)
            return solve(board, i+1, 0);
        if(board[i][j] != '.')
            return solve(board, i, j+1);
        
        for(char c = '1'; c<='9'; c++) {
            if(check(board, i,j, c)) {
                board[i][j] = c;
                if(solve(board, i, j+1))
                    return 1;
                board[i][j] = '.';
            }
        }
        
        return 0;
    }
    
    void solveSudoku(vector<vector<char>>& board) {
        solve(board, 0, 0);
    }
};