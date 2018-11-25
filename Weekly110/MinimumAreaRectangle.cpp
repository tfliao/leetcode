

#define INF (41000*41000)
#define hash(x,y) (x*40001+y)

class Solution {
public:

    int minAreaRect(vector<vector<int>>& points) {
        int best = INF;
        int i, j;
        int l = points.size();
        set<int> nodes;

        for (const auto& p : points) {
            nodes.insert(hash(p[0], p[1]));
        }

        for (int i=0;i<l;++i) {
            for (int j=i+1;j<l;++j) {
                int x1 = points[i][0];
                int y1 = points[i][1];
                int x2 = points[j][0];
                int y2 = points[j][1];

                if (x1 == x2 || y1 == y2)
                    continue;

                if (nodes.count(hash(x1, y2)) != 0 &&
                    nodes.count(hash(x2, y1)) != 0 ) {

                    int area = abs(x1-x2) * abs(y1-y2);
                    if (area < best && area != 0)
                        best = area;
                }
            }
        }

        if (best == INF)
            best = 0;

        return best;
    }
};
