class CBTInserter {
public:
    vector<TreeNode*> nodes;
    TreeNode* rt;

    CBTInserter(TreeNode* root) {
        queue<TreeNode*> Q;

        this->rt = root;
        Q.push(root);

        while (!Q.empty()) {
            TreeNode *node = Q.front(); Q.pop();
            nodes.push_back(node);
            if (node->left != NULL) Q.push(node->left);
            if (node->right != NULL) Q.push(node->right);
        }
    }

    int insert(int v) {
        int idx = nodes.size();
        int pidx = (idx - 1) / 2;

        TreeNode* parent = nodes[pidx];
        TreeNode* child = new TreeNode(v);
        if (parent->left == NULL) parent->left = child;
        else parent->right = child;
        nodes.push_back(child);

        return parent->val;
    }

    TreeNode* get_root() {
        return rt;
    }
};
