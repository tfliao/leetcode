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
    map<int, map<int, vector<int>>> val;
    
    void dfs(TreeNode* node, int x, int y) {
        if (node == NULL) 
            return;
        val[x][y].push_back(node->val);
        dfs(node->left, x-1, y+1);
        dfs(node->right, x+1, y+1);
    }
    
    vector<vector<int>> verticalTraversal(TreeNode* root) {
        vector<vector<int>> ans;
        val.clear();
        dfs(root, 0, 0);
        
        for (auto& xx : val) {
            vector<int> subans;
            for (auto& yy : xx.second) {
                vector<int> aa = yy.second;
                sort(aa.begin(), aa.end());
                for (auto a : aa) {
                    subans.push_back(a);
                }
            }
            ans.push_back(subans);
        }
        return ans;
    }
};
