class Solution {
public:
    vector<int> nextGreaterElement(vector<int>& nums1, vector<int>& nums2) {
        vector<int> ans;
        unordered_map<int,int> mp;
        stack<int> st;
        for(auto& i : nums2) {
            while(!st.empty() && st.top() < i) {
                mp[st.top()] = i;
                st.pop();
            }
            st.push(i);
        }
        
        for(auto& i : nums1) {
            if(mp[i]) {
                ans.push_back(mp[i]);
            } else 
                ans.push_back(-1);
        }
        
        return ans;
    }
};