/**
 * Definition for binary tree
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Solution {
public:
    vector<int> postorderTraversal(TreeNode *root) {
        vector<int> ret;
        stack<TreeNode *> s;
        s.push(root);
        TreeNode *tmp;
        while(!s.empty())
        {
            tmp = s.top();
            s.pop();
            if(tmp)
            {
                s.push(tmp->left);
                s.push(tmp->right);
                ret.insert(ret.begin(), tmp->val);
            }
        }
        return ret;
    }
};