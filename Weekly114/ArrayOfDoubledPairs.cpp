class Solution {
public:
    bool canReorderDoubled(vector<int>& A) {
        map<int, int> cnt;
        sort(A.begin(), A.end(), [](const int& x, const int& y) { return abs(x) < abs(y);} );

        for (auto a : A) cnt[a] ++;

        for (auto a : A) {
            if (cnt[a] == 0) {
                continue;
            }
            -- cnt[a];
            if (cnt[a*2] == 0) {
                return false;
            }
            -- cnt[a*2];
        }
        return true;
    }
};
