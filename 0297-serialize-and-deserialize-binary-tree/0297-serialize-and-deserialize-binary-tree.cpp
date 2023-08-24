/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Codec {
public:
    // Encodes a tree to a single string.
    void pre(TreeNode* root, string& s) {
        if(root) {
            s += to_string(root->val);
            s += " ";
            pre(root->left, s);
            pre(root->right, s);
        }
        else {
            s += "n ";
        }
    }
    string serialize(TreeNode* root) {
        string ans = "";
        pre(root, ans);
        return ans;
    }
    
    TreeNode* pre2(queue<string>& q) {
        string cur = q.front();
        q.pop();
        if(cur=="n")
            return nullptr;
        
        TreeNode* temp = new TreeNode(stoi(cur));
        temp->left = pre2(q);
        temp->right = pre2(q);
        
        return temp;
    }

    // Decodes your encoded data to tree.
    TreeNode* deserialize(string data) {
        queue<string> q;
        string t = "";
        for(int i=0; i<data.size(); i++) {
            if(data[i] == ' ') {
                q.push(t);
                t = "";
            }
            else {
                t+=data[i];
            }
        }
        if(t.size())
            q.push(t);
        return pre2(q);
    }
};

// Your Codec object will be instantiated and called as such:
// Codec ser, deser;
// TreeNode* ans = deser.deserialize(ser.serialize(root));