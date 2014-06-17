class Solution {
    void sum(TreeNode *root, int pathValue, int &ans)
    {
        if(root)
        {
            pathValue = pathValue * 10 + root->val;
            if(root->left == NULL && root->right == NULL)//leaf node
            {
                ans += pathValue;
            }
            else
            {
                if(root->left)
                {
                    sum(root->left, pathValue, ans);
                }
                if(root->right)
                {
                    sum(root->right, pathValue, ans);
                }
            }
        }
    }
public:
    int sumNumbers(TreeNode *root) {
        int ans = 0;
        sum(root, 0, ans);
        return ans;
    }
};