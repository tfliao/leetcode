class Solution {
public:
    int numPairsDivisibleBy60(vector<int>& time) {
        vector<int> cnt(60);
        for (auto t : time) {
            cnt[t%60] ++;
        }
        int ans = 0;
        for (int i=0;i<=30;++i) {
            int c = (60-i)%60;
            if (c == i) {
                ans += (cnt[i] * (cnt[i] - 1))/2;
            } else {
                ans += cnt[i] * cnt[c];
            }
        }
        return ans;
    }
};
