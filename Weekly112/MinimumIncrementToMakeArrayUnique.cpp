class Solution {
public:
    int minIncrementForUnique(vector<int>& A) {
        bool flag[80001] = {false};
        int cnt = 0;
        for (int a : A) {
            while (flag[a]) {
                ++cnt;
                ++a;
            }
            flag[a] = true;
        }
        return cnt;
    }
};
