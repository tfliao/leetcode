class Solution {
public:
    int longestOnes(vector<int>& A, int K) {
        int best = 0;
        vector<int> dp(A.size()+1, 0);
        for (int i=0;i<A.size();++i) {
            dp[i+1] = dp[i] + A[i];
        }
        for (int i=0;i<dp.size() - best; ++i) {
            int len = best + 1;
            while (i+len < dp.size() && dp[i + len] - dp[i] + K >= len) {
                best = len;
                ++len;
            }
        }
        return best;
    }
};
