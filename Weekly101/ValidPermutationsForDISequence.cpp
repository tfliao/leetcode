#define MOD(x) ((x)%1000000007)


class Solution {
public:

    int numPermsDISequence(string S) {
        int len = S.size();
        vector<vector<int>> dp(len+1, vector<int>(len+1, 0));

        dp[0][0] = 1;
        for(int i=1;i<=len;++i) {
            for (int j=0;j<i;++j) {
                int v = dp[i-1][j];
                if (S[i-1] == 'D') {
                    for (int k=0;k<=j;++k) {
                        dp[i][k] = MOD(dp[i][k] + v);
                    }
                } else {
                    for (int k=j+1;k<=i;++k) {
                        dp[i][k] = MOD(dp[i][k] + v);
                    }
                }
            }
        }

        int cnt = 0;
        for (int i=0;i<=len;++i) {
            cnt = MOD(cnt + dp[len][i]);
        }
        return cnt;

    }
};
