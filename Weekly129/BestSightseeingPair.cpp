class Solution {
public:
    int maxScoreSightseeingPair(vector<int>& A) {
        int best = 0;
        int bestP = A[0];
        for (int i=1;i<A.size();++i) {
            -- bestP;
            if (A[i] + bestP > best) {
                best = A[i] + bestP;
            }
            if (A[i] > bestP) {
                bestP = A[i];
            }
        }
        return best;
    }
};
