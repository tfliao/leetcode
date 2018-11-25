class Solution {
public:
    int bagOfTokensScore(vector<int>& tokens, int P) {
        int best = 0;
        int cur = 0;
        sort(tokens.begin(), tokens.end());

        int i = 0, j = tokens.size();
        while (i < j) {
            if (P >= tokens[i]) {
                P -= tokens[i];
                cur += 1;
                if (cur > best) best = cur;
                ++i;
            } else if (cur > 0) {
                --j;
                P += tokens[j];
                cur -= 1;
            } else {
                break;
            }
        }
        return best;
    }
};
