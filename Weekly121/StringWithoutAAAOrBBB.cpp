class Solution {
public:
    string strWithout3a3b(int A, int B) {
        string s;
        while (A > 0 || B > 0) {
            if (A == 0) {
                s += string(B, 'b');
                B = 0;
            } else if (B==0){
                s += string(A, 'a');
                A = 0;
            } else if (A > B) {
                s += "aab";
                A -= 2, B -= 1;
            } else if (A < B) {
                s += "bba";
                A -= 1, B -= 2;
            } else {
                s += "ab";
                A--, B--;
            }
        }

        return s;
    }
};
