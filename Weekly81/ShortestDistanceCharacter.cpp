class Solution {
public:
    vector<int> shortestToChar(string S, char C) {
        vector<int> r(S.length(), 99999);
        int last = -99999;
        for(int i=0;i<S.length();++i) {
            if (S[i] == C) {
                r[i] = 0;
                last = i;
            } else {
                r[i] = min(i - last, r[i]);
            }
        }
        last = 99999;
        for(int i=S.length()-1;i>=0;--i) {
            if (S[i] == C) {
                r[i] = 0;
                last = i;
            } else {
                r[i] = min(last - i, r[i]);
            }
        }

        return r;
    }
};