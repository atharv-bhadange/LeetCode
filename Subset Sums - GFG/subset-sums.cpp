//{ Driver Code Starts
#include<bits/stdc++.h> 
using namespace std; 

// } Driver Code Ends
class Solution
{
public:

    void solve(vector<int>& arr, int i, int sum, vector<int>& s) {
        if(i==arr.size()) {
            s.push_back(sum);
            return;
        }
        
        solve(arr, i+1, sum, s);
        solve(arr, i+1, sum+arr[i], s);
    }

    vector<int> subsetSums(vector<int> arr, int N)
    {
        // Write Your Code here
        int i=0;
        int sum = 0;
        vector<int> ans;
        
        solve(arr, i, sum, ans);
        
        return ans;
    }
};

//{ Driver Code Starts.
int main()
{
    int t;
    cin >> t;
    while (t--)
    {
        int N;
        cin>>N;
        vector<int> arr(N);
        for(int i = 0 ; i < N ; i++){
            cin >> arr[i];
        }
        Solution ob;
        vector<int> ans = ob.subsetSums(arr,N);
        sort(ans.begin(),ans.end());
        for(auto sum : ans){
            cout<< sum<<" ";
        }
        cout<<endl;
    }
    return 0;
}
// } Driver Code Ends