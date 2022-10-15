class Solution {
public:
    int compress(vector<char>& chars) {
        int idx = 0;
        int i = 0;
        while(i<chars.size()) {
            int j = i;
            while(j<chars.size() && chars[j] == chars[i]) {
                j++;
            }
            chars[idx++] = chars[i];
            if(j-i>1) {
                string temp = to_string(j-i);
                for(int k = 0; k<temp.size(); k++) {
                    chars[idx++] = temp[k];
                }
            }
            i = j;
        }
        
        return idx;
    }
};