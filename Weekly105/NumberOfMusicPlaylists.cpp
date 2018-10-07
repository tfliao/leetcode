#define MOD(x) ((x)%1000000007LL)
#define LL long long

class Solution {
public:
    int numMusicPlaylists(int N, int L, int K) {
        //     len, songs
        LL dp[101][101] = {0};
        dp[0][0] = 1;

        for (int i=1;i<=L;++i) {
            for (int j=1;j<=N;++j) {
                if (j > K)
                    dp[i][j] += dp[i-1][j] * (j-K);
                if (j <= N)
                    dp[i][j] += dp[i-1][j-1];
                dp[i][j] = MOD(dp[i][j]);
            }
        }
        LL ans = dp[L][N];
        for (int i=2;i<=N;++i) {
            ans = MOD(ans * i);
        }
        return (int)ans;
    }
};
