class Solution {
public:
    vector<int> addNegabinary(vector<int>& P, vector<int>& Q) {
        reverse(P.begin(), P.end());
        reverse(Q.begin(), Q.end());
        int L = max(P.size(), Q.size());
        P.resize(L);
        Q.resize(L);

        vector<int> R(L);
        for (int i=0;i<L;++i) R[i] = P[i] + Q[i];

        for (int i=0;i<R.size();++i) {
            if (R[i] > 1 || R[i] < 0) {
                if (i == R.size()-1) {
                    R.push_back(0);
                }
                if (R[i] < 0) {
                    R[i] = 1;
                    R[i+1] += 1;
                }
                if (R[i] > 1) {
                    R[i] = R[i] % 2;
                    R[i+1] += -1;
                }
            }
        }
        while (!R.empty() && R.back() == 0) R.pop_back();
        if (R.empty()) R.push_back(0);
        reverse(R.begin(), R.end());
        return R;
    }
};
