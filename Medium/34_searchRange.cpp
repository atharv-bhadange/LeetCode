class Solution
{
public:
    int lower(vector<int> &n, int t)
    {
        int l = 0;
        int r = n.size() - 1;
        int mid;
        while (l <= r)
        {
            mid = (r - l) / 2 + l;
            if (n[mid] < t)
                l = mid + 1;
            else
                r = mid - 1; // move the right pointer when n[mid]==t so that the left pointer remains at the first from left occurrence of target
        }

        if (l == n.size() || n[l] != t)
            return -1;

        return l;
    }

    int upper(vector<int> &n, int t)
    {
        int l = 0;
        int r = n.size() - 1;
        int mid;
        while (l <= r)
        {
            mid = (r - l) / 2 + l;
            if (n[mid] > t)
                r = mid - 1;
            else
                l = mid + 1; // move the left pointer when n[mid]==t so that the right pointer remains at the first from right occurrence of target
        }

        if (r < 0 || n[r] != t)
            return -1;

        return r;
    }

    vector<int> searchRange(vector<int> &nums, int target)
    {
        vector<int> ans(2);

        ans[0] = lower(nums, target);
        ans[1] = upper(nums, target);

        return ans;
    }
};

// use of modified binary search