class Solution {
public:
    vector<vector<int>> colorBorder(vector<vector<int>>& grid, int r0, int c0, int color) {
        vector<vector<int>> result = grid;
        int tc = grid[r0][c0];
        int R = grid.size();
        int C = grid[0].size();
        int dx[] = {0,1,0,-1}, dy[] = {1,0,-1,0};

        queue<int> Q;
        Q.push(r0*1024 + c0);
        grid[r0][c0] *= -1;

        while (!Q.empty()) {
            int x = Q.front() / 1024;
            int y = Q.front() % 1024;
            Q.pop();

            bool border = false;
            for (int i=0;i<4;++i) {
                int nx = x + dx[i];
                int ny = y + dy[i];
                if (nx >= R || nx < 0 || ny >= C || ny < 0) {
                    border = true;
                    continue;
                }
                if (grid[nx][ny] < 0) {
                    continue;
                }
                if (abs(grid[nx][ny]) != tc) {
                    border = true;
                    continue;
                }
                Q.push(nx * 1024 + ny);
                grid[nx][ny] *= -1;
            }
            if (border) {
                result[x][y] = color;
            }
        }
        return result;
    }
};
