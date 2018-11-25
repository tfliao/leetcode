

class Solution {
public:

    vector<int> root;
    vector<int> cnt;

    int _find(int x) {
        if (root[x] == x) return x;
        return root[x] = _find(root[x]);
    }

    void merge(int x, int y) {
        int rx = _find(x);
        int ry = _find(y);
        if (rx == ry) return;
        root[rx] = ry;
        cnt[ry] += cnt[rx];
    }


    int removeStones(vector<vector<int>>& stones) {
        int sz = stones.size();

        root = vector<int>(sz);
        cnt = vector<int>(sz);
        for (int i=0;i<sz;++i) {
            root[i] = i;
            cnt[i] = 1;
        }

        for (int i=0;i<sz;++i) {
            for (int j=i+1;j<sz;++j) {
                if (stones[i][0] == stones[j][0] ||
                    stones[i][1] == stones[j][1]) {
                    merge(i, j);
                }
            }
        }
        int res = 0;
        for (int i=0;i<sz;++i) {
            if (root[i] == i) {
                res += cnt[i] - 1;
            }
        }
        return res;
    }
};
