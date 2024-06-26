class Solution {
public:
    string intToRoman(int num) {
        vector<int> nums = {1000, 900, 500, 400, 100, 90, 50, 40, 10, 9, 5, 4, 1};
        
        vector<string> st = {"M", "CM", "D", "CD", "C", "XC", "L", "XL", "X", "IX", "V", "IV", "I"};
        string ans = "";
        for(int i=0; i<13; i++) {
            while(num >= nums[i]) {
                num -= nums[i];
                ans += st[i];
            }
        }
        
        return ans;
    }
};