class Solution {
public:
    int maxSubarraySumCircular(vector<int>& A) {
        bool pos = false;
        int mx = -30000*30000;
        int mn = 30000*30000;

        int sum = 0;
        int ss = 0, sl = 0;

        for (auto a : A) {
            sum += a;
            if (a > 0)
                pos = true;

            ss += a;
            sl += a;
            mx = max(mx, sl);
            mn = min(mn, ss);

            ss = min(ss,0);
            sl = max(sl, 0);

        }
        if (!pos)
            return mx;
        return max(mx, sum - mn);
    }
};
