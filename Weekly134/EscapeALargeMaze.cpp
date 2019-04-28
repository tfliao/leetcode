#define SZ (1000000)
#define MOD (1LL << 30)

class Solution {
public:
    long long hash(long long x, long long y) {
        return x * MOD + y;
    }

    bool isEscapePossible(vector<vector<int>>& blocked, vector<int>& source, vector<int>& target) {
        int visit = 1;
        queue<long long> Q;
        set<long long> mark;
        int dx[] = {0,1,0,-1}, dy[] = {1,0,-1,0};

        long long h = hash(source[0], source[1]);

        for (auto b : blocked) {
            mark.insert(hash(b[0], b[1]));
        }

        Q.push(h);
        mark.insert(h);
        while (!Q.empty()) {
            long long x = Q.front() / MOD;
            long long y = Q.front() % MOD;
            Q.pop();
            for (int i=0;i<4;++i) {
                long long nx = x + dx[i], ny = y + dy[i];

                if (nx >= SZ || ny >= SZ || nx < 0 || ny < 0) {
                    continue;
                }
                long long h = hash(nx, ny);
                if (x == target[0] && y == target[1]) {
                    return true;
                }
                if (mark.count(h) != 0) {
                    continue;
                }
                ++ visit;
                if (visit > 20000) {
                    return true;
                }
                mark.insert(h);
                Q.push(h);
            }
        }
        return false;
    }
};
