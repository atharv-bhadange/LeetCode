class Solution
{
public:
    int maximumUniqueSubarray(vector<int> &nums)
    {
        unordered_set<int> s;
        int cur_sum = 0, max_sum = 0, l = 0;
        for (int r = 0; r < nums.size(); r++)
        {
            while (s.find(nums[r]) != s.end()) // while the number is repeated, remove it from the sum
            {
                cur_sum -= nums[l];
                s.erase(nums[l]);
                l++;
            }
            cur_sum += nums[r]; // add the current num
            s.insert(nums[r]);  // insert it into the set
            max_sum = max(max_sum, cur_sum);
        }
        return max_sum;
    }
};