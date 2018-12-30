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
    bool check(TreeNode* root, int val) {
        if (root == NULL) return true;
        if (root->val != val) return false;
        return check(root->right, val) && check(root->left, val);
    }

    bool isUnivalTree(TreeNode* root) {
        if (root == NULL) return true;
        return check (root, root->val);
    }
};
