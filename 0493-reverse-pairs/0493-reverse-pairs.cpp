class Solution {
public:
    int ans;
    void merge(vector<int>& nums, int high, int mid, int low) {
        // vector<int> temp;
        int i = low;
        int j = mid+1;

        while(i<=mid && j<=high) {
            if((long)nums[i] > (long)2*nums[j]) {
                // temp.push_back(nums[i++]);
                ans += (mid - i +1);
                j++;
            }
            else {
                // temp.push_back(nums[j++]);
                i++;
            }
        }
        
        sort(nums.begin()+low, nums.begin()+high+1);
        
        // for(int i=0; i<temp.size(); i++) {
        //     nums[i+low] = temp[i];
        // }
    }
    void mergeSort(vector<int>& nums, int low, int high) {
        if(low >= high) 
            return;
        int mid = (low+high)/2;
        
        mergeSort(nums, low, mid);
        mergeSort(nums, mid+1, high);
        merge(nums, high, mid, low);
    }
    int reversePairs(vector<int>& nums) {
        int n = nums.size();
        ans = 0;
         mergeSort(nums, 0, n-1);
        return ans;
    }
};