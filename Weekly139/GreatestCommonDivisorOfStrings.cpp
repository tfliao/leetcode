class Solution {
public:
    bool check(const string& S, const string& D) {
        int l = D.length();
        for (int i=0;i<S.length();++i) {
            if (S[i] != D[i%l]) {
                return false;
            }
        }
        return true;
    }

    string gcdOfStrings(string str1, string str2) {
        int l1 = str1.length(), l2 = str2.length();
        string best;
        for (int i=1;i<=l1 && i<=l2;++i) {
            if (l1 % i == 0 && l2 % i == 0) {
                string D = str1.substr(0, i);
                if (check(str1, D) && check(str2, D)) {
                    best = D;
                }
            }
        }
        return best;
    }
};
