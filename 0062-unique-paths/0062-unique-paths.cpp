class Solution {
public:
    int uniquePaths(int m, int n) {
        m--;
        n--;
        if(n>m) {
            swap(m,n);
        }
       
        long ans = 1;
        int j = 1;
        for(int i=m+1; i<m+n+1; i++) {
            ans *= i;
            ans /= j++;
        }
        
        return ans;
    }
};