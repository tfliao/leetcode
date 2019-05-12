#define R 23058430092369395ULL
#define MOD(x) (((x) + R) % R)
#define P 47
class Solution {
public:
    typedef long long LL;
    int verify(const string& S, int L) {
        unordered_set<LL> mark;
        LL v = 0;
        LL tail = 1;
        for (int i=0;i<L;++i) {
            v = MOD(v * P + (S[i]-'a'));
            tail = MOD(tail * P);
        }
        mark.insert(v);
        for (int i=L;i<S.length();++i) {
            v = MOD(v * P + (S[i]-'a'));
            v = MOD(v - MOD(tail * (S[i-L]-'a')));
            if (mark.count(v) != 0) {
                return i-L+1;
            }
            mark.insert(v);
        }
        return -1;
    }


    string longestDupSubstring(string S) {
        int L = 0, H = S.length(), M;
        int ans = 0, leng = 0;
        while (H-L > 1) {
            M = (H+L) / 2;
            int r = verify(S, M);
            if (r > 0) {
                ans = r;
                leng = M;
                L = M;
            } else {
                H = M;
            }
        }
        return S.substr(ans, leng);
    }
};
