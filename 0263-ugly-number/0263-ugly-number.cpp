class Solution {
public:
    vector<int> primeFactors(int n) 
    { 
        vector<int> res;
        while (n%2 == 0) 
        { 
            res.push_back(2); 
            n = n/2; 
        } 

        for (int i = 3; i <= sqrt(n); i = i+2) 
        { 
            while (n%i == 0) 
            { 
                res.push_back(i); 
                n = n/i; 
            } 
        } 

        if (n > 2) 
            res.push_back(n); 
        
        return res;
    } 
    
    bool isUgly(int n) {
        if(n<=0)
            return false;
        vector<int> res = primeFactors(n);
        
        for(int i=0; i<res.size(); i++)
            if(res[i]!=2 && res[i]!=3 && res[i]!=5)
                return false;
        
        return true;
    }
};