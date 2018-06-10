class Solution {
public:
    string shiftingLetters(string S, vector<int>& shifts) {
        int sh = 0;
        for(int i=S.length()-1;i>=0;--i) {
            sh = (sh+shifts[i]) % 26;
            S[i] = 'a' + (S[i]-'a'+sh)%26;
        }
        return S;
    }
};