class Solution {
public:
    int maxSatisfied(vector<int>& C, vector<int>& G, int X) {
        int sum = 0;
        vector<int> S(C.size() + 1, 0);
        for (int i=0;i<C.size();++i) {
            if (G[i] == 0) {
                sum += C[i];
                C[i] = 0;
            }
            S[i+1] = S[i] + C[i];
        }
        int best = 0;
        for (int i=X;i<S.size();++i) {
            if (S[i] - S[i-X] > best) {
                best = S[i] - S[i-X];
            }
        }
        return sum + best;
    }
};
