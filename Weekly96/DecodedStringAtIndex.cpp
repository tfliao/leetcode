class Solution {
public:
    char ans = 0;
    int off(const string& S, int p, long long len, int K) {
        int o = 0;
        if (len >= K) {
            return (K - 1) % len;
        }
        
        if (S[p] >= '2' && S[p] <= '9') {
            o = off(S, p+1, len * (S[p]-'0'), K);
            if (-1 == o) return -1;
            return o % len;
        } else {
            if (len + 1 == K) {
                ans = S[p];
                return -1;
            }
            o = off(S, p+1, len+1, K);
            if (-1 == o) return -1;
            if (o == len) {
                ans = S[p];
                return -1;
            }
            return o;
        }
    }
    
    
    string decodeAtIndex(string S, int K) {
        off(S, 0, 0, K);
        string r = string(1, ans);
        return r;
    }
};
