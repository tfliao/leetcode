class Solution {
public:
    string removeOuterParentheses(string S) {
        string r;
        int cnt = 0;
        for (char c : S) {
            bool append = true;
            if (c == '(') {
                ++ cnt;
                if (cnt == 1) append = false;
            } else if (c ==')') {
                --cnt;
                if (cnt == 0) append = false;
            }
            if (append) {
                r += c;
            }
        }
        return r;
    }
};
