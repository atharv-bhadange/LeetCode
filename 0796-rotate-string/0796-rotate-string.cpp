class Solution {
public:
    bool rotateString(string s, string goal) {
        if(s.size() != goal.size())
            return 0;
        list<char> l1, l2;
        for(int i=0; i<s.size(); i++) 
            l1.push_back(s[i]);
        
        for(int i=0; i<s.size(); i++) 
            l2.push_back(goal[i]);
        
        for(int i=0; i<s.size(); i++) {
            char front = l2.front();
            l2.pop_front();
            l2.push_back(front);
            if(l1 == l2)
                return 1;
        }
        
        return 0;
    }
};