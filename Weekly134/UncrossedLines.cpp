class Solution {
public:
    int cost[501][501];

    int dp(const vector<int>& A, const vector<int>& B, int x, int y) {
        if (x < 0 || y < 0) {
            return 0;
        }
        if (cost[x][y] != -1) {
            return cost[x][y];
        }
        if (A[x] == B[y]) {
            return cost[x][y] = dp(A, B, x-1, y-1) + 1;
        } else {
            return cost[x][y] = max(dp(A, B, x, y-1), dp(A, B, x-1, y));
        }
    }

    int maxUncrossedLines(vector<int>& A, vector<int>& B) {
        memset(cost, -1, sizeof(cost));
        return dp(A, B, A.size()-1, B.size()-1);
    }
};
