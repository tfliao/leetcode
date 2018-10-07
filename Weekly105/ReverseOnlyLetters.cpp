class Solution {
public:
    string reverseOnlyLetters(string S) {
        string ret;
        int p =  S.length()-1;
        for (int i=0;i<S.length();++i) {
            if (isalpha(S[i])) {
                while (!isalpha(S[p])) --p;
                ret += S[p];
                --p;
            } else {
                ret += S[i];
            }
        }
        return ret;
    }
};
