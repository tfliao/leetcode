#define INF (999999)

class Solution {
public:
    map<pair<int,int>, int> dp;
    vector<int> sum;

    int all_seg(int b, int e, int K, int r) {
        if (r == 1) {
            if (e == b) {
                return INF;
            }
            int ret = calc(b, e, K);
            return ret;
        }

        int best = INF;
        for (int i=1 ; i <= e - b - r + 1; i += K-1) {
            int sub_ans = all_seg(b+i, e, K, r-1) + calc(b, b+i, K) ;
            if (sub_ans < best)
                best = sub_ans;
        }
        return best;
    }

    int calc(int b, int e, int K) {
        pair<int,int> r = make_pair(b,e);
        if ( (e - b - 1) % (K -1) != 0) return INF;
        if (dp.count(r) != 0) return dp[r];
        if (e - b == 1) return 0;
        if (e - b == K) return dp[r] = sum[e-1] - sum[b-1];
        return dp[r] = sum[e-1] - sum[b-1] + all_seg(b, e, K, K);
    }


    int mergeStones(vector<int>& stones, int K) {
        if ((stones.size() - 1) % (K-1) != 0) return -1;
        dp.clear();
        sum = vector<int>(stones.size() + 1, 0);
        for (int i=0;i<stones.size();++i) {
            sum[i+1] = sum[i] + stones[i];
        }

        return calc(1, stones.size() + 1, K);
    }
};
