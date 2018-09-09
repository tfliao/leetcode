class Solution {
public:
    bool compare(int p, int q, int l, string& S) {
        for (int i=0;i<l;++i) {
            if (S[(p+i)%l] != S[(q+i)%l])
                return S[(p+i)%l] < S[(q+i)%l];
        }
        return true;
    }

    string orderlyQueue(string S, int K) {
        if (K == 1) {
            int best = 0;
            for (int i=1;i<S.length();++i) {
                if (compare(i, best, S.length(), S))
                    best = i;
            }
            S = S.substr(best) + S.substr(0, best);
        } else {
            sort(S.begin(), S.end());
        }
        return S;
    }
};
