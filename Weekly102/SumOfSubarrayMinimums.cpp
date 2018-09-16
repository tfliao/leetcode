#define INF (1LL<<30)
#define MOD(x) ((x) % 1000000007LL)

class Solution {
public:
    typedef long long LL;

    LL f(const vector<int>& A, int l, int r) {
        if (l >= r) return 0;
        // [l, r)
        LL mn = INF;
        LL idx = -1;
        for (int i=l;i<r;++i) {
            if (A[i] < mn) {
                mn = A[i];
                idx = i;
            }
        }

        LL res_left = f(A, l, idx);
        LL res_right = f(A, idx+1, r);

        return MOD( (idx - l + 1) * (r - idx) * mn + res_left + res_right) ;
    }

    int sumSubarrayMins(vector<int>& A) {
        return f(A, 0, A.size());
    }
};
