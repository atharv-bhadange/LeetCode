class Solution {
public:
    vector<int> pivotArray(vector<int>& nums, int pivot) {
        vector<int> p1, p2; 
        int cnt = 0;
        for(int i=0; i<nums.size(); i++) {
            if(nums[i] < pivot)
                p1.push_back(nums[i]);
            else if(nums[i] == pivot)
                cnt++;
            else 
                p2.push_back(nums[i]);
        }
        
        while(cnt--)
            p1.push_back(pivot);
        
        p1.insert(p1.end(), p2.begin(), p2.end());
        
        return p1;
    }
};