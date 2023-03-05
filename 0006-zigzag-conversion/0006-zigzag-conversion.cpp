class Solution {
public:
    string convert(string s, int numRows) {
        if(numRows == 1)
            return s;
        int k = min(numRows,int(s.size()));
        vector<string> t(k);
        int currRow = 0;
        bool down = 0;
        for(auto &c : s) {
            t[currRow] += c;
            if(currRow==0 || currRow==numRows-1) {
                down = !down;
            }
            currRow += down ? 1 : -1;
        }
        
        string ans;
        for(auto &row : t) ans+=row;
        return ans;
    }
};