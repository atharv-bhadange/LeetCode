//{ Driver Code Starts
#include<bits/stdc++.h>

using namespace std;


// } Driver Code Ends
class Solution{

    // Function to find the trapped water between the blocks.
    public:
    long long trappingWater(int arr[], int n){
        // code here
        vector<int> mxl(n),mxr(n);
        mxl[0] = arr[0];
        
        for(int i=1; i<n; i++) {
            mxl[i] = max(mxl[i-1], arr[i]);
        }
        
        mxr[n-1] = arr[n-1];
        
        for(int i=n-2; i>=0; i--) {
            mxr[i] = max(mxr[i+1], arr[i]);
        }
        
        long long ans = 0;
        for(int i=0; i<n; i++) {
            ans += min(mxr[i], mxl[i]) - arr[i];
        }
        
        return ans;
    }
};

//{ Driver Code Starts.

int main(){
    
    int t;
    //testcases
    cin >> t;
    
    while(t--){
        int n;
        
        //size of array
        cin >> n;
        
        int a[n];
        
        //adding elements to the array
        for(int i =0;i<n;i++){
            cin >> a[i];            
        }
        Solution obj;
        //calling trappingWater() function
        cout << obj.trappingWater(a, n) << endl;
        
    }
    
    return 0;
}
// } Driver Code Ends