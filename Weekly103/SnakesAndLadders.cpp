class Solution {
public:

    int snakesAndLadders(vector<vector<int>>& board) {
        int N = board.size();
        map<int, int> jump;

        for (int i=0;i<N;++i) {
            for (int j=0;j<N;++j) {
                int idx = i * N + j + 1;
                int x = N - 1 - i;
                int y = (i%2==0?j:N-1-j);
                if (board[x][y] != -1) {
                    jump[idx] = board[x][y];
                }
            }
        }

        map<int, int> cost;
        queue<int> q;
        q.push(1);
        cost[1] = 0;

        while (!q.empty()) {
            int p = q.front();
            int c = cost[p];
            q.pop();
            for (int i=1;i<=6;++i) {
                int n = p + i;
                if (jump.count(n) != 0)
                    n = jump[n];
                if (cost.count(n) != 0)
                    continue;
                cost[n] = c + 1;
                q.push(n);
                if (n == N * N) return c+1;
            }
        }
        return -1;
    }
};
