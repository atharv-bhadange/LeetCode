class Solution {
public:
    bool isValidSudoku(vector<vector<char>>& board) {
        bool used1[9][9] = {0}, used2[9][9] = {0}, used3[9][9] = {0};
        for(int i=0; i<9; i++) 
            for(int j=0; j<9; j++) 
                if(board[i][j] != '.') {
                    int num = board[i][j] - '0' - 1;
                    int k = (i/3) * 3 + (j/3);
                    if(used1[i][num] || used2[j][num] || used3[k][num]) 
                        return 0;
                    used1[i][num] = used2[j][num] = used3[k][num] = 1;
                }
        
        return 1;
    }
};