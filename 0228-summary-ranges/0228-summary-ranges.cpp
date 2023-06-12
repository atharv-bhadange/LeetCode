class Solution {
public:
    vector<string> summaryRanges(vector<int>& nums) {
        int n = nums.size();
        vector<string> ans;
        if(n<=1) {
            if(n==1) {
                ans.push_back(to_string(nums[0]));
            }
            
            return ans;
        } else {
            long long st=0;
            long long end=0;
            for(int i=0; i<n-1; i++) {
                // cout<<nums[i]<<" "<<nums[i+1]<<endl;
                string res = "";
                long long cnt = 0;
                while(i < n-1 && nums[i] == nums[i+1]-1) {
                    cnt++;
                    end=nums[i+1];
                    i++;
                }
                if(cnt==0)
                    ans.push_back(to_string(nums[i]));
                else {
                    st = end-cnt;
                    res = to_string(st) + "->" + to_string(end);
                    ans.push_back(res);
                }
                
            }
            if(nums[n-1] != nums[n-2] + 1) {
                ans.push_back(to_string(nums[n-1]));
            }
        }
        
        return ans;
    }
};