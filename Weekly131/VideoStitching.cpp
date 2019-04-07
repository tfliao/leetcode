class Solution {
public:
    int videoStitching(vector<vector<int>>& clips, int T) {
        const int BIG = 128;
        vector<int> dp(T+1, BIG);
        sort(clips.begin(), clips.end());
        dp[0] = 0;
        for (const auto& c : clips) {
            for (int i=c[0] + 1; i <= c[1] && i <= T ; ++i) {
                if (dp[c[0]] + 1 < dp[i]) {
                    dp[i] = dp[c[0]] + 1;
                }
            }
        }
        if (dp[T] >= BIG) return -1;
        return dp[T];
    }
};
