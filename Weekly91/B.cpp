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
    vector<int> res;
    
    int dfs(TreeNode* root, TreeNode* target, int K) {
        if (root == NULL) {
            return -1;
        }
        if (root == target) {
            append(root, K);
            return 1;
        }
        int ret;
        if ((ret = dfs(root->right, target, K)) >= 0) {
            if (K-ret == 0) {
                res.push_back(root->val);
            } else {
                append(root->left, K-ret-1);
            }
            return ret + 1;
        } else if ((ret = dfs(root->left, target, K)) >= 0) {
            if (K-ret == 0) {
                res.push_back(root->val);
            } else {
                append(root->right, K-ret-1);
            }
            return ret + 1;
        }
        return -1;
    }

        
        
    void append(TreeNode* node, int K) {
        if (node == NULL) return;
        if (K < 0) return;
        if (K == 0) {
            res.push_back(node->val);
            return;
        }
        append(node->left, K-1);
        append(node->right, K-1);
    }
    
    vector<int> distanceK(TreeNode* root, TreeNode* target, int K) {
        res.clear();
        dfs(root, target, K);
        return res;
    }
};

