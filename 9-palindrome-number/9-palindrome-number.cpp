class Solution {
public:
    bool isPal(int x) {
        long long int y = 0;
        int temp = x;
        while(x) {
            int l = x%10;
            y = y*10 + l;
            x/=10;
        }
        
        return temp == y;
    }
    
    bool isPalindrome(int x) {
        if(x<0) return 0;
        return isPal(x);
    }
};