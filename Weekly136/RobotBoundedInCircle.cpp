class Solution {
public:
    string I;
    set<pair<int,int>> visited;
    int d;
    int x, y;

    bool simulate() {
        static int dx[] = {0, 1, 0, -1}, dy[] = {1, 0, -1, 0};
        for (int i=0;i<I.length();++i) {
            if (I[i] == 'G') {
                x += dx[d];
                y += dy[d];
            } else if (I[i] == 'R') {
                d = (d+1) % 4;
            } else {
                d = (d+3) % 4;
            }
        }
        auto p = make_pair(x, y);
        if (visited.count(p) != 0) return true;
        visited.insert(p);
        return false;
    }


    bool isRobotBounded(string instructions) {
        visited.clear();
        I = instructions;
        d = 0;
        x = y = 0;
        visited.insert(make_pair(0,0));

        for (int i=0;i<4;++i) {
            if (simulate()) return true;
        }
        return false;

    }
};
