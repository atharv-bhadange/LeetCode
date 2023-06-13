class Solution {
public:
    string capitalizeTitle(string title) {
        vector<string> strs;
        int n = title.size();
        for(int i=0; i<n; i++) {
            string s = "";
            while(i<n & title[i]!=' ')
                s+=title[i++];
            strs.push_back(s);
        }
        title = "";
        
        for(auto& x: strs) {
            transform(x.begin(), x.end(), x.begin(), ::tolower);
            if(x.size()>2) {
                x[0] = toupper(x[0]);
            }
            title += x;
            title += " ";
        }
        title.pop_back();
        return title;
    }
};