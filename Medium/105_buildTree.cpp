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
    int preIdx = 0;
    unordered_map<int, int> mp; // O(1) lookup

    // O(n) lookup
    /*
    int findInInorder(vector<int> &inorder, int &inSt, int &inEnd, int &key)
    {
        for (int j = inSt; j <= inEnd; j++)
        {
            if (inorder[j] == key)
                return j;
        }
        return -2;
    }
    */

    TreeNode *recur(vector<int> &preorder, vector<int> &inorder, int inSt, int inEnd)
    {

        if (inSt > inEnd)
            return nullptr;

        TreeNode *temp = new TreeNode(preorder[preIdx++]);

        if (inSt == inEnd)
            return temp;

        int splitIdx = mp[temp->val];
        temp->left = recur(preorder, inorder, inSt, splitIdx - 1);
        temp->right = recur(preorder, inorder, splitIdx + 1, inEnd);

        return temp;
    }

    TreeNode *buildTree(vector<int> &preorder, vector<int> &inorder)
    {
        for (int i = 0; i < inorder.size(); i++)
            mp[inorder[i]] = i;
        return recur(preorder, inorder, 0, preorder.size() - 1);
    }
};