class Solution {
public:
    int offset ;
    string s;
    int dfs() {
        int score = 0;
        if (s[offset] == '(') {
            ++ offset;
            if (s[offset] == ')') {
                ++offset;
                return 1;
            }
            while (s[offset] == '(') {
                int r = dfs();
                score += r;
            }
            ++offset;
            return score * 2;
            
        } else {
            return 0;
        }
    }
    
    int scoreOfParentheses(string S) {
        offset = 0;
        s = S;
        return dfs();
    }
};