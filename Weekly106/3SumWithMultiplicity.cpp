#define MOD(x) ((x) % 1000000007)

class Solution {
public:
    int threeSumMulti(vector<int>& A, int target) {
        vector<int> dp(301, 0);
        int ans = 0;
        for (int i=0;i<A.size();++i) {
            int r = target - A[i];
            if (r >=0 )
                ans = MOD(ans + dp[r]);
            for (int j=0;j<i;++j) {
                dp[A[i]+A[j]] ++;
            }
        }
        return ans;
    }
};
