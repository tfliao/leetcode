class Solution {
public:
    int lastStoneWeightII(vector<int>& stones) {
        vector<int> dp(3001,0);
        int sum = 0;
        dp[0] = 1;
        for(int s : stones) {
            for (int i=3000; i>=s;--i) {
                if (dp[i-s] == 1) {
                    dp[i] = 1;
                }
            }
            sum += s;
        }
        int best = 3000;
        for (int i=0;i<=3000;++i) {
            if (dp[i]) {
                int r = abs((sum - i) - i);
                if (r < best) best = r;
            }
        }
        return best;
    }
};
