#include <string> 
class Solution {
public:
    int strStr(string haystack, string needle) {
        auto found = haystack.find(needle);
        // cout<<found<<endl;
        if(found == string::npos)
            return -1;
        
        return found;
    }
};