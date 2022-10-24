class Solution {
public:
    int helper(vector<string>& arr, string& str, int curr){
        unordered_set<char> vis;
        for(int i=0;i<str.size();i++){
            vis.insert(str[i]);
        }
        
        if(str.size()!=vis.size())
            return 0;
        
        int ans=str.length();
        for(int i=curr;i<arr.size();i++){
            string str2 = str+arr[i];
            int smallans=helper(arr, str2, i+1);
            ans=max(smallans, ans);
        }
        
        return ans;
    }
    int maxLength(vector<string>& arr) {
//         unordered_set<char> st(s.begin(), s.end());
//         if(st.size() != s.size())
//             return 0;
        
//         int ans = s.size();
//         for(int i=0; i<arr.size(); i++)
//             ans = max(ans, maxLength(arr, s+arr[i], i+1));
        
        // return ans;
        string str="";
        return helper(arr, str, 0);
    }
};