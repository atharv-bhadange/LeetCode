class Solution {
public:
    vector<int> asteroidCollision(vector<int>& asteroids) {
        stack<int> st; 
        vector<int> ans;
        for(int i=0; i<asteroids.size(); i++) {
            if(st.empty())
                st.push(asteroids[i]);
            else {
                int x = st.top();
                if(x * asteroids[i] > 0) {
                    st.push(asteroids[i]);
                }
                else if(x > 0 && asteroids[i]<0){
                    int z = abs(x);
                    int y = abs(asteroids[i]);
                    
                    if(z == y) {
                        st.pop();
                    }
                    else if(z<y) {
                        st.pop();
                        // st.push(asteroids[i]);
                        i--;
                    }
                }
                else 
                    st.push(asteroids[i]);
                    
            }
        }
        
        while(!st.empty()) {
            ans.push_back(st.top());
            st.pop();
        }
        
        reverse(ans.begin(), ans.end());
        
        return ans;
    }
};