class Solution {
public:
    bool canThreePartsEqualSum(vector<int>& A) {
        for (int i=1;i<A.size();++i) {
            A[i] += A[i-1];
        }
        if (A.back() % 3 != 0) return false;
        int target = A.back() / 3;
        int p, q;

        for (p = 0; p < A.size(); ++p) {
            if (A[p] == target) break;
        }
        if (p == A.size()) return false;
        for (q = A.size()-2; q > p; --q) {
            if (A.back() - A[q] == target) break;
        }
        if (p == q) return false;

        return true;
    }
};
