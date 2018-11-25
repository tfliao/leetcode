#define R (1000000007)
#define MOD(x) ((x+R)%R)

class Solution {
public:
    typedef long long LL;
    int distinctSubseqII(string S) {
        int l = S.length();
        vector<LL> dp(l + 1, 0);
        vector<int> last(128, -1);

        dp[0] = 1;
        for (int i=0;i<l;++i) {
            int idx = i+1;
            char c = S[i];
            dp[idx] = MOD(dp[idx-1] * 2);
            if (last[c] != -1) {
                dp[idx] = MOD(dp[idx]-dp[last[c]]);
            }
            last[c] = i;
        }

        return MOD(dp[l] - 1);
    }
};
