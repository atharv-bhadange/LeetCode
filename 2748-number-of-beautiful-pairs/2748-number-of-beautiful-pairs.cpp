class Solution {
public:
    int countBeautifulPairs(vector<int>& nums) {
        int n = nums.size();
        int ans = 0;
        for(int i=0; i<n; i++) {
            for(int j=i+1; j<n; j++) {
                string s1 = to_string(nums[i]);
                string s2 = to_string(nums[j]);
                int i1 = s1[0] - '0';
                int i2 = s2[s2.size()-1] - '0';
                
                if(__gcd(i1,i2) == 1) {
                    ans++;
                    // cout<<i1<<" "<<i2<<endl;
                }
            }
        }
        
        return ans;
    }
};