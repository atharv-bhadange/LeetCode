class Solution {
public:
    bool canMakeSubsequence(string str1, string str2) {
        int n = str1.size(), m = str2.size();
        int i = 0;
        int j = 0;
        while(i < n && j < m) {
            if(str2[j] - str1[i] == 1 || str2[j] - str1[i] == -25 || str2[j] - str1[i] == 0) {
                j++;
            }
            i++;
        }
        
        if(j==m) {
            return true;
        }
        
        return false;
    }
};