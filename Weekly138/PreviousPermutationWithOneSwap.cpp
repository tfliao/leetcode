class Solution {
public:
    vector<int> prevPermOpt1(vector<int>& A) {
        int p = A.size()-2, q;
        for (p;p>=0;--p) {
            if (A[p] > A[p+1]) break;
        }
        if (p < 0) return A;
        int best = -1;
        for (q=A.size()-1;q>=p;--q) {
            if (A[q] < A[p]) {
                if (best == -1 || A[q] > A[best]) best = q;
            }
        }
        swap(A[p], A[best]);
        return A;
    }
};
