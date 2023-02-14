class Solution {
public:
    string addBinary(string a, string b) {
        int az = a.size();
        int bz = b.size();
        reverse(a.begin(), a.end());
        reverse(b.begin(), b.end());
        int i=0; 
        int j=0;
        int carry = 0;
        string ans = "";
        while(i<az && j<bz) {
            if((a[i]-'0') + (b[j]-'0') + carry == 0){
                ans.insert(0, "0");
                carry = 0;
            }
            else if ((a[i]-'0') + (b[j]-'0') + carry == 1) {
                // cout<<"here";
                ans.insert(0, "1");
                carry = 0;
            }
            else if (a[i]-'0' + b[j]-'0' + carry == 2) {
                ans.insert(0, "0");
                carry = 1;
            }
            else if (a[i]-'0' + b[j]-'0' + carry == 3) {
                ans.insert(0, "1");
                carry = 1;
            }
            i++; j++;
            // cout<<ans<<endl;
        }
        
        while(i<az) {
            if(a[i]-'0' + carry == 0){
                ans.insert(0, "0");
                carry = 0;
            }
            else if (a[i]-'0' + carry == 1) {
                ans.insert(0, "1");
                carry = 0;
            }
            else if (a[i]-'0' + carry == 2) {
                ans.insert(0, "0");
                carry = 1;
            }
           i++;
        }
        while(j<bz) {
            if(b[j]-'0' + carry == 0){
                ans.insert(0, "0");
                carry = 0;
            }
            else if (b[j]-'0' + carry == 1) {
                ans.insert(0, "1");
                carry = 0;
            }
            else if (b[j]-'0' + carry == 2) {
                ans.insert(0, "0");
                carry = 1;
            }
            j++;
        }
        if(carry) {
            ans.insert(0, "1");
        }
        
        
        
        return ans;
    }
};