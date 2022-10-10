class Solution {
public:
    void setZeroes(vector<vector<int>>& m) {
        int rows = m.size();
        int cols = m[0].size();
        int col0 = 0;
        int row0 = 0;
        for(int i=0; i<rows; i++) {
            
            for(int j=0; j<cols; j++) {
                if(m[i][j]==0)
                {
                    if(j==0) col0 = 1;
                    if(i==0) row0 = 1;
                    m[i][0] = 0;
                    m[0][j] = 0;
                }
            }
        }
        
        for(int i=rows-1; i>=1; i--) {
            for(int j=cols-1; j>=1; j--) {
                if(m[i][0] == 0 || 
                    m[0][j] == 0) {
                    m[i][j] = 0;
                }
            }
        }
        
        if(row0) 
            for(int j=0; j<cols; j++)
                m[0][j] = 0;
        if(col0) 
            for(int i=0; i<rows; i++)
                m[i][0] = 0;
    }
    
    
};