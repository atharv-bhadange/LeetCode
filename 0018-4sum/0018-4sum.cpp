class Solution {
public:
    vector<vector<int>> fourSum(vector<int>& nums, int target) {
        int n = nums.size();
        sort(nums.begin(), nums.end());
        set<vector<int>> ans1;
        for(int i=0; i<n; i++) {
            for(int j=i+1; j<n; j++) {
                for(int k=j+1; k<n; k++) {
                    long long t = (long long)target - (long long)nums[i] - (long long)nums[j] - (long long)nums[k];
                    vector<int> temp;
                    if(binary_search(nums.begin()+k+1, nums.end(), t)) {
                        temp.push_back(nums[i]);
                        temp.push_back(nums[j]);
                        temp.push_back(nums[k]);
                        temp.push_back(t);
                        sort(temp.begin(), temp.end());
                        ans1.insert(temp);
                        temp.clear();
                    }
                }
            }
        }
        vector<vector<int>> ans(ans1.begin(), ans1.end());
        
        return ans;
    }
};