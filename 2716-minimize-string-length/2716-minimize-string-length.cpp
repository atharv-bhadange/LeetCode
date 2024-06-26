class Solution {
public:
    int minimizedStringLength(string s) {
        unordered_set<char> st;
        for(auto &c: s){
            st.insert(c);
        }
        
        return st.size();
    }
};