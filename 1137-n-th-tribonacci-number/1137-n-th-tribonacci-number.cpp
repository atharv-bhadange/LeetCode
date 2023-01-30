class Solution {
public:
    int tribonacci(int n) {
        // if(n<=1) {
        //     return n;
        // }
        // if(n==2)
        //     return 1;
        long long arr[40] = {0};
        arr[0] = 0;
        arr[1] = 1;
        arr[2] = 1;  
        
        for(int i=0; i<n; i++) {
            arr[i+3] = arr[i] + arr[i+1] + arr[i+2];
        }
        
        return arr[n];
    }
};