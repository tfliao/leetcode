class Solution {
public:
    bool check(const vector<int>& ww, int limit, int D) {
        int remain = limit;
        for (auto w : ww ) {
            if (remain < w) {
                -- D;
                remain = limit;
            }
            if (remain < w) return false;
            remain -= w ;
        }
        return D > 0;
    }

    int shipWithinDays(vector<int>& weights, int D) {
        int l=1, h=500*50000+1;
        while (l + 1 < h) {
            int m = (l+h)/2;
            if (check(weights, m, D)) {
                h = m;
            } else {
                l = m;
            }
        }
        return h;
    }
};
