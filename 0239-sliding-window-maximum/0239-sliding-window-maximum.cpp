class Solution {
public:
    vector<int> maxSlidingWindow(vector<int>& nums, int k) {
        list<int> lt;
        int i=0, j=0;
        int n = nums.size();
        vector<int> ans;
        int mx = INT_MIN;
        while(j<n) {
            while(!lt.empty() && lt.back() < nums[j])
                lt.pop_back();
            lt.push_back(nums[j]);
            if(j-i+1 < k) {
                j++;
            }
            else {
                ans.push_back(lt.front());
                if(nums[i] == lt.front()) {
                    lt.pop_front();
                }
                i++;
                j++;
            }
        }
        
        return ans;
    }
};