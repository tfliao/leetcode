class Solution {
public:
    int minAddToMakeValid(string S) {
        int ans = 0;
        int cnt = 0;
        for (char c : S) {
            if (c == '(') {
                cnt ++;
            } else {
                cnt --;
            }
            if (cnt < 0) {
                ans ++;
                cnt = 0;
            }
        }
        return ans + cnt;
    }
};
