class Solution {
public:
    int minFlipsMonoIncr(string S) {
        int l = S.length();
        vector<int> z(l+1), o(l+1);
        for (int i=0;i<l;++i) {
            z[i+1] = z[i] + (S[i] == '0'?1:0);
            o[i+1] = o[i] + (S[i] == '0'?0:1);
        }
        int best = l;
        for (int i=0;i<=l;++i) {
            int c = o[i]-o[0] + z[l]-z[i];
            if (c < best) best = c;
        }
        return best;
    }
};
