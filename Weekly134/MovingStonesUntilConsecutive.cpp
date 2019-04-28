class Solution {
public:
    vector<int> numMovesStones(int a, int b, int c) {
        vector<int> p({a,b,c});
        sort(p.begin(), p.end());

        int left = p[1] - p[0] - 1;
        int right = p[2] - p[1] - 1;
        int m = (left > 0?1:0) + (right > 0?1:0);
        if (right == 1 || left == 1) {
            m = 1;
        }

        return vector<int>({m, left + right});
    }
};
