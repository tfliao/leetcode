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
    vector<int> A;

    void build(TreeNode* root) {
        if (root == NULL) return;
        build(root->left);
        A.push_back(root->val);
        build(root->right);
    }

    TreeNode* Construct(int b, int e) {
        if (b >= e) return NULL;
        int m = b;
        for (int i=b;i<e;++i) {
            if (A[i] >= A[m])
                m = i;
        }
        //printf("Select %d as root, (%d, %d)\n", A[m], b, e);
        TreeNode * n = new TreeNode(A[m]);
        n->left = Construct(b, m);
        n->right = Construct(m+1, e);
        return n;
    }

    TreeNode* insertIntoMaxTree(TreeNode* root, int val) {
        A.clear();
        build(root);

        A.push_back(val);
        return Construct(0, A.size());
    }
};
