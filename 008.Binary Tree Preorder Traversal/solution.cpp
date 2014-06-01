class Solution {
public:
    vector<int> preorderTraversal(TreeNode *root)
    {
        vector<int> ret;
        stack<TreeNode *> s;
        s.push(root);
        TreeNode *node;
        while(!s.empty())
        {
            node = s.top();
            s.pop();
            if(node)
            {
                ret.push_back(node->val);
                s.push(node->right);
                s.push(node->left);
            }
        }
        return ret;
    }
};