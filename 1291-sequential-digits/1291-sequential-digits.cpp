class Solution {
public:
    vector<int> sequentialDigits(int low, int high) {
        string s = "123456789";
        
        vector<int> ans; 
        for(int i=0; i<9; i++) {
            string t = "";
            for(int j=i; j<9; j++) {
                t += s[j];
                int n = stoi(t);
                
                if(low <= n && n <= high) {
                    ans.push_back(n);
                }
            }
        }
        sort(ans.begin(), ans.end());
        return ans;
    }
};