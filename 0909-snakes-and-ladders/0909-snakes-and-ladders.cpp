class Solution {
public:
    int snakesAndLadders(vector<vector<int>>& board) {
        int n = board.size();
        vector<pair<int,int>> cells(n*n + 1);
        vector<int> column(n);
        for(int i=0; i<n; i++) 
            column[i] = i;
        
        int label = 1;
        for(int row = n-1; row>=0; row--) {
            for(auto col : column) {
                cells[label++] = {row, col};
            }
            reverse(column.begin(), column.end());
        }
        
        vector<int> dist(n*n + 1, -1);
        queue<int> q;
        dist[1] = 0;
        q.push(1);
        
        while(!q.empty()) {
            int curr = q.front();
            q.pop();
            
            for (int next = curr+1; next<= min(curr + 6, n*n); next++) {
                auto [row, col] = cells[next];
                int destination = board[row][col] == -1 ? next : board[row][col];
                if(dist[destination] == -1) {
                    dist[destination] = dist[curr] + 1;
                    q.push(destination);
                }
            }
        }
        
        
        return dist[n*n];
    }
};