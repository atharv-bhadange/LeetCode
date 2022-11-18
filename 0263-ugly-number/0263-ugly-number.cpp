class Solution {
public:
    int kdwd(int divid, int divis) {
        while(divid%divis==0) 
            divid/=divis;
        return divid;
    }
    
    bool isUgly(int n) {
        if(n<=0)
            return false;
        
        vector<int> ugly = {2, 3, 5};
        for(auto &x : ugly) 
            n = kdwd(n, x);
        
        return n==1;
    }
};