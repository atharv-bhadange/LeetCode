/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
class Solution
{
public:
    vector<int> v;
    void inT(TreeNode *p)
    {
        if (p)
        {
            inT(p->left);
            v.push_back(p->val);
            inT(p->right);
        }
    }

    int rangeSumBST(TreeNode *root, int low, int high)
    {
        inT(root);
        int i;
        for (i = 0; i < v.size(); i++)
        {
            if (v[i] == low)
                break;
        }

        // for(i=0; i<v.size(); i++)
        //  cout<<v[i]<<" ";
        int ans = 0;
        while (v[i] != high)
            ans += v[i++];
        ans += v[i];

        return ans;
    }
};
// jugaad solution

class Solution {
public:
    int rangeSumBST(TreeNode* root, int low, int high)
    {
        if(root == nullptr)
        {
            return 0;
        }
        if(root->val >= low && root->val <= high)
        {
            return rangeSumBST(root->left,low,high) + root->val + rangeSumBST(root->right,low,high);
        }
        else
        {
            return rangeSumBST(root->left,low,high) + rangeSumBST(root->right,low,high);
        }
    }
    
};

// better solution
