class Solution {
public:

    int maxSumAfterPartitioning(vector<int>& A, int K) {
        vector<int> dp(A.size() + 1, 0);

        for (int i=0;i<A.size();++i) {
            int mx = A[i];
            dp[i+1] = dp[i] + mx;
            for (int j=1; j < K && i-j>=0;++j) {
                mx = max(mx, A[i-j]);
                int cand = dp[i-j] + mx * (j+1);
                if (cand > dp[i+1]) dp[i+1] = cand;

            }
        }
        return dp.back();
    }
};
