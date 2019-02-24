class Solution {
public:
    vector<int> gridIllumination(int N, vector<vector<int>>& lamps, vector<vector<int>>& queries) {
        map<int, int> x, y, xy, yx;

        map<pair<int,int>, int> L;

        for (auto& l :lamps) {
            x[l[0]] ++;
            y[l[1]] ++;
			xy[l[0]-l[1]] ++;
			yx[l[1]+l[0]] ++;
            L[make_pair(l[0], l[1])] ++;
        }

        vector<int> result;
        for (auto& q : queries) {
            if (x[q[0]] > 0 ||
                y[q[1]] > 0 ||
                xy[q[0]-q[1]] > 0 ||
                yx[q[1]+q[0]] > 0 ) {
                    result.push_back(1);
                }
            else
                result.push_back(0);

            for (int i = q[0] - 1; i <= q[0] + 1; ++i) {
                for (int j = q[1] - 1; j <= q[1] + 1; ++j) {
                    auto p = make_pair(i, j);
                    if (L.count(p) != 0) {
                        int c = L[p];
                        L.erase(p);
                        x[i] -= c;
                        y[j] -= c;
                        xy[i-j] -= c;
                        yx[i+j] -= c;
                    }
                }
            }
        }
        return result;

    }
};
