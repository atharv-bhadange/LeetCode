class NumArray //segment tree question
{
public:
    vector<int> seg;
    int n;

    void buildTree(vector<int> &nums, int pos, int left, int right)
    {
        if (left == right)
        {
            seg[pos] = nums[left];
            return;
        }
        int mid = (left + right) / 2;
        buildTree(nums, 2 * pos + 1, left, mid);
        buildTree(nums, 2 * pos + 2, mid + 1, right);
        seg[pos] = seg[2 * pos + 1] + seg[2 * pos + 2];
    }

    void updateUtil(int pos, int left, int right, int index, int val)
    {

        if (index < left || index > right)
            return;

        if (left == right)
        {
            if (left == index)
                seg[pos] = val;
            return;
        }

        int mid = (left + right) / 2;
        updateUtil(2 * pos + 1, left, mid, index, val);
        updateUtil(2 * pos + 2, mid + 1, right, index, val);
        seg[pos] = seg[2 * pos + 1] + seg[2 * pos + 2];
    }

    int rangeUtil(int qlow, int qhigh, int low, int high, int pos)
    {
        if (qlow <= low && qhigh >= high)
        {
            return seg[pos];
        }
        if (qlow > high || qhigh < low)
        {
            return 0;
        }

        int mid = low + (high - low) / 2;
        return (rangeUtil(qlow, qhigh, low, mid, 2 * pos + 1) + rangeUtil(qlow, qhigh, mid + 1, high, 2 * pos + 2));
    }

    NumArray(vector<int> &nums)
    {
        if (nums.size() > 0)
        {
            n = nums.size();
            seg.resize(4 * n, 0);
            buildTree(nums, 0, 0, n - 1);
        }
    }

    void update(int index, int val)
    {
        if (n == 0)
            return;
        updateUtil(0, 0, n - 1, index, val);
    }

    int sumRange(int left, int right)
    {
        if (n == 0)
            return 0;
        return rangeUtil(left, right, 0, n - 1, 0);
    }
};

/**
 * Your NumArray object will be instantiated and called as such:
 * NumArray* obj = new NumArray(nums);
 * obj->update(index,val);
 * int param_2 = obj->sumRange(left,right);
 */





vector<int> nums(30000);
    vector<int> seg(4*30000);
class NumArray {
public:
    // int N = 30000;
    
    NumArray(vector<int>& n) {
        for(int i=0; i<nums.size(); i++)
            nums[i] = n[i];
        
        build(0,0,n.size()-1);
        
    }
    
    void build(int idx, int l, int r)
    {
        if(l==r)
        {
            seg[idx] = nums[l];
            return;
        }
        int mid = (l+r)/2;
        build(2*idx+1, l, mid);
        build(2*idx+2, mid+1, r);
        seg[idx] = seg[2*idx+1] + seg[2*idx+2];
    }
    
    void upBuild(int idx, int l, int r,int upI, int val)
    {
        if(upI<l || upI>r)
            return;
        if(l==upI && r==upI)
        {
            seg[idx] = val;
            return;
        }
        int mid = (l+r)/2;
        upBuild(2*idx+1, l, mid, upI, val);
        upBuild(2*idx+2, mid+1, r, upI, val);
        seg[idx] = seg[2*idx+1] + seg[2*idx+2];
    }
    
    void update(int index, int val) {
        // nums[index] = val;
        if(nums)
        upBuild(0,0,nums.size()-1,index, val);
    }
    
    int sum(int idx, int l, int r, int lmax, int rmax)
    {
        if(l>=lmax && r<= rmax)
            return seg[idx];
        if(rmax<l || lmax>r)
            return INT_MIN;
        
        int mid = (l+r)/2;
        int left = sum(2*idx+1,l,mid,lmax,rmax);
        int right = sum(2*idx+2,mid+1,r,lmax,rmax);
        
        return left + right;
    }
    
    int sumRange(int left, int right) {
        return sum(0,0,nums.size()-1,left,right);
    }
};

/**
 * Your NumArray object will be instantiated and called as such:
 * NumArray* obj = new NumArray(nums);
 * obj->update(index,val);
 * int param_2 = obj->sumRange(left,right);
 */