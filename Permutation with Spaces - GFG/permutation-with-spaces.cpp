//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
class Solution{
public:
    vector<string> ans;
    void solve(string ip, string op) {
        if(ip.size() == 1) {
            op.push_back(ip[0]);
            ans.push_back(op);
            return;
        }
        
        string op1 = op;
        op1.push_back(ip[0]);
        op.push_back(ip[0]);
        op1.push_back(' ');
        
        ip.erase(ip.begin());
        
        solve(ip,op);
        solve(ip,op1);
    }
    vector<string> permutation(string S){
        // Code Here
        string tmp = "";
        solve(S, tmp);
        
        sort(ans.begin(), ans.end());
        
        return ans;
    }
};

//{ Driver Code Starts.

int  main(){
    int t;
    cin>>t;
    while(t--){
        string S;
        cin>>S;
        vector<string> ans;
        Solution obj;
        ans = obj.permutation(S);
        for(int i=0;i<ans.size();i++){
            cout<<"("<<ans[i]<<")";
        }
        cout << endl;
    }
}

// } Driver Code Ends