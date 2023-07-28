//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution {
  public:
    int ans = 0;
    void solve(vector<int>& arr, int k, int idx) {
        if(arr.size() == 1) {
            ans = arr[0];
            return;
        }
        
        idx = (idx+k)%arr.size();
        arr.erase(arr.begin()+idx);
        
        solve(arr,k,idx);
    }
    int safePos(int n, int k) {
        // code here
        vector<int> arr(n);
        for(int i=0; i<n; i++)
            arr[i] = i+1;
        k--;
        
        solve(arr, k, 0);
        
        return ans;
    }
};



//{ Driver Code Starts.
int main() {
    int t;
    cin >> t;
    while (t--) {
        int n,k;
        
        cin>>n>>k;

        Solution ob;
        cout << ob.safePos(n,k) << endl;
    }
    return 0;
}
// } Driver Code Ends