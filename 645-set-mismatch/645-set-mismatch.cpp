class Solution {
public:
    vector<int> findErrorNums(vector<int>& nums) {
        long long n = nums.size();
        long long act_sum = (n*(n+1))/2;
        long long sum = accumulate(nums.begin(),nums.end(), 0);
        
        long long act_sq_sum = (n*(n+1)*(2*n+1))/6;
        long long sq_sum = 0;
        for(auto& x : nums)
            sq_sum += x*x;
        
        long long dif_sum = (sum-act_sum);
        long long dif_sq_sum = sq_sum - act_sq_sum;
        
        long long plus = dif_sq_sum / dif_sum;
        
        int duplicate = (plus+dif_sum)/2;
        int missing = plus - duplicate;
        
        return {duplicate,missing};
    }
};