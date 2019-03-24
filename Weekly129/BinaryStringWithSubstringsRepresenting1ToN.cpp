class Solution {
public:
    bool queryString(string S, int N) {
        if (N > S.length() * 32) {
            return false;
        }
        vector<int> mark(N+1, false);
        for (int i=0;i<S.length();++i) {
            long long v = 0;
            for (int j=0;i+j < S.length() && j < 32; ++j) {
                v = (v << 1) + S[i+j] - '0';
                if (v > N) continue;
                mark[v] = true;
            }
        }
        for (int i=1;i<=N;++i) {
            if (mark[i] == false) return false;
        }
        return true;
    }
};
