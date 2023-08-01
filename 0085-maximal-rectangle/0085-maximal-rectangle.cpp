class Solution {
public:
    int MAH(vector<int>& height) {
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
    
    int maximalRectangle(vector<vector<char>>& matrix) {
        int rows = matrix.size();
        int cols = matrix[0].size();
        vector<vector<int>> myMat;
        int t_rows = 1;
        for(int t_rows=1; t_rows<=rows; t_rows++) {
            vector<int> temp(cols);
            for(int i=0; i<t_rows; i++){
                for(int j=0; j<cols; j++) {
                    temp[j] += matrix[i][j] - '0';
                    if(matrix[i][j] == '0')
                        temp[j] = 0;
                }
            }
            
            myMat.push_back(temp);
        }
        
        int ans = INT_MIN;
        for(auto& x: myMat) 
            ans = max(ans, MAH(x));
        
         
        return ans;
    }
};