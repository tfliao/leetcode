class Solution {
public:
    int mincostTickets(vector<int>& days, vector<int>& costs) {
        vector<int> dp(366, 0);
        vector<int> dd(366, 0);

        for (auto d : days) {
            dd[d] = 1;
        }

        for (int i=1;i<=365;++i) {
            dp[i] = 366000;
            if (dd[i] == 0)
                dp[i] = dp[i-1];
            if (i >= 1) dp[i] = min(dp[i], dp[i-1] + costs[0]);
            if (i >= 7) dp[i] = min(dp[i], dp[i-7] + costs[1]);
            if (i >= 30) dp[i] = min(dp[i], dp[i-30] + costs[2]);
        }
        return dp[365];
    }
};
