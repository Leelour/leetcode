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
    int maxSum(TreeNode *root, int &max)
    {
        if(root)
        {
            if(root->left == NULL && root->right == NULL)//is leaf node
            {
                max = max > root->val? max : root->val;
                return root->val > 0? root->val : 0;
            }
            else
            {
                int lSum = 0, rSum = 0, total = 0, ret;
                if(root->left)
                {
                    lSum  = maxSum(root->left, max);
                }
                if(root->right)
                {
                    rSum = maxSum(root->right, max);
                }
                total = lSum + rSum + root->val;
                max = max > total ? max : total;
                if(lSum > rSum)
                {
                    ret = lSum + root->val > 0 ? lSum + root->val : 0;
                }
                else
                {
                    ret = rSum + root->val > 0 ? rSum + root->val : 0;
                }
                return ret;
            }
        }
        else
        {
            return 0;
        }
    }
public:
    int maxPathSum(TreeNode *root) {
        int max = 0x80000000;
        maxSum(root, max);
        return max;
    }
};