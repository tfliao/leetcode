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
    
    string dfs(TreeNode* root) {
        if (root->left == NULL && root->right == NULL) {
            string r(1, root->val + 'a');
            return r;
        }
        string best(1, 'z'+1);
        if (root->left != NULL) {
            string l = dfs(root->left);
            l += (root->val + 'a');
            if (l < best) best = l;
        }
        if (root->right != NULL) {
            string r = dfs(root->right);
            r += (root->val + 'a');
            if (r < best) best = r;
        }
        return best;
    }
    
    string smallestFromLeaf(TreeNode* root) {
        return dfs(root);
    }
};
