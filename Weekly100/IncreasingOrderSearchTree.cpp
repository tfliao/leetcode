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
    TreeNode* r;
    TreeNode** next;

    void _append(TreeNode* node) {
        *next = new TreeNode(node->val);
        next = &(*next)->right;
    }

    void _travel(TreeNode* node) {
        if (node == NULL) return;
        _travel(node->left);
        _append(node);
        _travel(node->right);
    }

    TreeNode* increasingBST(TreeNode* root) {
        r = new TreeNode(0);
        next = &r->right;
        _travel(root);
        return r->right;
    }
};
