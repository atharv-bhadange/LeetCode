class Solution {
public:
    bool searchMatrix(vector<vector<int>>& matrix, int target) {
        int m = matrix.size();
        int n = matrix[0].size();
        int up = m-1;
        int right = 0;
        while(up>=0 && right<n) {
            if(matrix[up][right]>target) 
                up--;
            else if(matrix[up][right]<target) 
                right++;
            else
                return true;
        }
        
        return false;
    }
};