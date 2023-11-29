class Solution {
public:
    int hammingWeight(uint32_t n) {
        string s = "";
        while(n)
        {
            int l = n%2;
            s+=to_string(l);
            n/=2;
        }
        int ans=0;
        for(int i=0; i<s.size(); i++)
            if(s[i]=='1')
                ans++;
        return ans;
    }
};