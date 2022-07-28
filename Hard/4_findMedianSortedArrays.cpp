class Solution
{
public:
    double findMedianSortedArrays(vector<int> &nums1, vector<int> &nums2)
    {
        int m = nums1.size();
        int n = nums2.size();

        vector<int> a(m + n);
        int i = 0, j = 0, k = 0;
        while (i < m && j < n)
        {
            if (nums1[i] < nums2[j])
                a[k++] = nums1[i++];
            else if (nums2[j] < nums1[i])
                a[k++] = nums2[j++];
            else
            {
                a[k++] = nums1[i++];
                a[k++] = nums2[j++];
            }
        }

        while (i < m)
            a[k++] = nums1[i++];
        while (j < n)
            a[k++] = nums2[j++];

        if ((m + n) % 2 == 0)
        {
            return double(a[(m + n) / 2] + a[(m + n) / 2 - 1]) / 2;
        }
        else
            return double(a[(m + n) / 2]);
    }
};

// easiest hard problem 