#define R (1000000007)

/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Solution {
public:
    int sum ;

    void dfs(TreeNode* node, int v) {
        v = (v * 2 + node->val) % R;
        if (node->left == NULL && node->right == NULL) {
            sum = (sum + v) % R;
        } else {
            if (node->left != NULL) {
                dfs(node->left, v);
            }
            if (node->right != NULL) {
                dfs(node->right, v);
            }
        }
    }

    int sumRootToLeaf(TreeNode* root) {
        sum = 0;
        dfs(root, 0);
        return sum;
    }
};
