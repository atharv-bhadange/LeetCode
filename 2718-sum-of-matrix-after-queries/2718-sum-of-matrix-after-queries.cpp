class Solution {
public:
    long long matrixSumQueries(int n, vector<vector<int>>& queries) {
        int rowCount=0, colCount=0;
        vector<bool> rowSeen(n), colSeen(n);
        long long ans = 0;
        for(int i=queries.size()-1; i>=0; i--) {
            int type = queries[i][0], index = queries[i][1], val = queries[i][2];
            
            if(type==0 && !rowSeen[index]) {
                rowSeen[index] = 1;
                rowCount++;
                ans += 1LL * (n-colCount) * val;
            }
            else if (type==1 && !colSeen[index]) {
                colSeen[index] = 1;
                colCount++;
                ans += 1LL * (n-rowCount) * val;
            }
        }
        
        return ans;
    }
};