#define R (1000000007LL)
#define MOD(x) ((long)(x) % R)
class Solution {
public:
    int numFactoredBinaryTrees(vector<int>& A) {
        map<int, int> idx;
        vector<long> dp(A.size(), 0);
        sort(A.begin(), A.end());
        long ans = 0;
        for(int i=0;i<A.size();++i) {
            idx[A[i]] = i;
            dp[i] = 1;
            for(int j=0;j<i;++j) {
                if (A[i] % A[j] != 0) continue;
                int d = A[i]/A[j];
                if (idx.count(d) == 0) continue;
                int k = idx[A[i]/A[j]];
                dp[i] = MOD(dp[i] + dp[j] * dp[k]);
            }
            ans = MOD(ans + dp[i]);
        }
        return ans;
    }
};