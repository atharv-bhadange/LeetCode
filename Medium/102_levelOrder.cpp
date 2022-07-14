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
    vector<vector<int>> levelOrder(TreeNode *root)
    {
        queue<vector<TreeNode *>> q;
        vector<TreeNode *> cur_lvl;
        cur_lvl.push_back(root);
        q.push(cur_lvl);

        vector<vector<int>> ans;

        while (!q.empty())
        {
            vector<TreeNode *> cl = q.front();
            q.pop();
            vector<int> cld;
            int i = 0;
            int j = cl.size();
            vector<TreeNode *> nl;

            while (i < j)
            {
                if (cl[i])
                {
                    cld.push_back(cl[i]->val);
                    nl.push_back(cl[i]->left);
                    nl.push_back(cl[i]->right);
                }
                i++;
            }

            if (nl.size() != 0)
            {
                q.push(nl);
                ans.push_back(cld);
            }
        }

        return ans;
    }
};

// bfs solution using queue<vector<TreeNode* >>