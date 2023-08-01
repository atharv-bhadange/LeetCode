class Solution {
public:
    int largestRectangleArea(vector<int>& height) {
        vector<int> toleft;
        vector<int> toright;
        int n = height.size();
        stack<int> st;
        for(int i=0; i<n; i++) {
            if(st.empty())
                toleft.push_back(-1);
            else if(!st.empty() && height[st.top()] < height[i]) {
                toleft.push_back(st.top());
            }
            else if(!st.empty() && height[st.top()] >= height[i]) {
                while(!st.empty() && height[st.top()] >= height[i]) {
                    st.pop();
                }
                
                if(st.empty()) 
                    toleft.push_back(-1);
                else 
                    toleft.push_back(st.top());
            }
            st.push(i);
        }
        while(!st.empty())
            st.pop();
        
        for(int i=n-1; i>=0; i--) {
            if(st.empty())
                toright.push_back(n);
            else if(!st.empty() && height[st.top()] < height[i]) {
                toright.push_back(st.top());
            }
            else if(!st.empty() && height[st.top()] >= height[i]) {
                while(!st.empty() && height[st.top()] >= height[i]) {
                    st.pop();
                }
                if(st.empty()) 
                    toright.push_back(n);
                else 
                    toright.push_back(st.top());
            }
            st.push(i);
        }
        reverse(toright.begin(), toright.end());
        int ans = INT_MIN;
        for(int i=0; i<n; i++) {
            ans = max(ans,height[i]*(toright[i]-toleft[i]-1));
        }
        
        return ans;
    }
};