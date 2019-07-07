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
    vector<TreeNode*> result;
    set<int> del;

    TreeNode* dfs(TreeNode* node, bool add) {
        TreeNode* ret = node;
        if (node == NULL) return NULL;

        if (del.count(node->val) != 0) {
            ret = NULL;
        }
        if (ret != NULL & add) {
            result.push_back(node);
        }
        node->left = dfs(node->left, ret == NULL);
        node->right = dfs(node->right, ret == NULL);
        return ret;

    }

    vector<TreeNode*> delNodes(TreeNode* root, vector<int>& to_delete) {
        result.clear();
        del.clear();
        for(auto v : to_delete) { del.insert(v); }
        dfs(root, true);
        return result;
    }
};
