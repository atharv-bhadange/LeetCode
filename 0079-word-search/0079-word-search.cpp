class Solution {
public:
    bool dfs(vector<vector<char>>& board, string &word, int i, int j, int idx) {
        
        if(idx==word.size())
            return true;
        if(i<0 || j<0 || i>=board.size() || j>=board[0].size() || word[idx]!=board[i][j])
            return false;
        
        
        
        char cur = board[i][j];
        board[i][j] = '*';
        bool ans = dfs(board, word, i+1, j, idx+1) || dfs(board, word, i-1, j, idx+1) || dfs(board, word, i, j+1, idx+1) || dfs(board, word, i, j-1, idx+1);
        board[i][j] = cur;
        
        
        return ans;
    }
    
    bool exist(vector<vector<char>>& board, string word) {
        bool ans = 0;
        for(int i=0; i<board.size(); i++)
            for(int j=0; j<board[0].size(); j++)
                if(board[i][j]==word[0])
                    ans |= dfs(board, word, i, j, 0);
        
        return ans;
    }
};