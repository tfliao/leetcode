class Solution {
public:
    bool parse(const string& exp, int& offset) {
        char c = exp[offset ++];
        bool r = false;
        switch(c) {
            case 't':
                return true;
            case 'f':
                return false;
            case '!':
                ++offset;
                r = parse(exp, offset);
                ++offset;
                return ! r;
            case '&':
                r = true;
                while (exp[offset] != ')') {
                    ++offset;
                    r &= parse(exp, offset);
                }
                ++offset;
                return r;
            case '|':
                r = false;
                while (exp[offset] != ')') {
                    ++offset;
                    r |= parse(exp, offset);
                }
                ++offset;
                return r;
        }
        return false;
    }

    bool parseBoolExpr(string expression) {
        int off = 0;
        return parse(expression, off);
    }
};
