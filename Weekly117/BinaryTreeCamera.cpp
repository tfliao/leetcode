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

    int CM(long long x) {
        return x / 2048 / 2048;
    }
    int cM(long long x) {
        return x / 2048 % 2048;
    }
    int cm(long long x) {
        return x % 2048;
    }

    long long dfs(TreeNode* root) {
        int dp[2][3] = {0};
        // LR, (-C-M, -C+M, +C)
        dp[0][2] = dp[1][2] = 1023;

        if (root->left != NULL) {
            long long r = dfs(root->left);
            dp[0][0] = cm(r);
            dp[0][1] = cM(r);
            dp[0][2] = CM(r);
        }
        if (root->right != NULL) {
            long long r = dfs(root->right);
            dp[1][0] = cm(r);
            dp[1][1] = cM(r);
            dp[1][2] = CM(r);
        }

        long long v0 = dp[0][1] + dp[1][1];
        long long v1 = min(min(dp[0][2] + dp[1][1], dp[0][1] + dp[1][2]), dp[0][2]+dp[1][2]);
        long long v3 = 1 + min(min(dp[0][0], dp[0][1]), dp[0][2]) + min(min(dp[1][0], dp[1][1]), dp[1][2]);
        //printf("%d %d %d\n", v0, v1, v3);
        return v3 * 2048 * 2048 + v1 * 2048 + v0 ;
    }


    int minCameraCover(TreeNode* root) {
        long long r = dfs(root);

        return min(cM(r), CM(r));
    }
};
