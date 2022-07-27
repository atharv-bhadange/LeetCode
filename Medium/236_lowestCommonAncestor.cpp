/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Solution
{
public:
    bool dfs(TreeNode *p, vector<TreeNode *> &path, TreeNode *k)
    {
        if (p == nullptr)
            return false;

        path.push_back(p); //first push element in vector

        if (p->val == k->val) // if found return true
            return true;

        if ((p->left && dfs(p->left, path, k)) || (p->right && dfs(p->right, path, k))) // if any of the subtrees finds it return true
            return true;

        path.pop_back(); // not found that means this is the worng path so pop back and return false
        return false;
    }

    TreeNode *lowestCommonAncestor(TreeNode *root, TreeNode *p, TreeNode *q)
    {
        vector<TreeNode *> path1, path2;
        dfs(root, path1, p); // dfs to find path to the nodes to search
        dfs(root, path2, q);

        int i = 0;
        for (int i = 0; i < path1.size(); i++)
            cout << path1[i]->val << " ";
        cout << endl;
        for (int i = 0; i < path2.size(); i++)
            cout << path2[i]->val << " ";
        cout << endl;

        // return nullptr;
        for (i = 0; i < path1.size() && i < path2.size(); i++) //find the first uncommon element 
            if (path1[i] != path2[i])
                break;
        if (path1.size() < path2.size())
            return path1[i - 1];
        else
            return path2[i - 1];
    }
};