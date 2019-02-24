class Solution {
public:
    void find_rook(vector<vector<char>>& board, int& x, int&y ) {
        for (x=0;x<8;++x)
            for (y=0;y<8;++y)
                if (board[x][y] == 'R')
                    return;

        return;
    }

    int cap(vector<vector<char>>& board, int x, int y, int dx, int dy) {
        //printf("%d %d, %d %d\n", x, y, dx, dy);
        while(true) {
            x = x+dx, y = y+dy;
            if (x < 0 || x >= 8 || y < 0 || y >= 8) return 0;

            if (board[x][y] == 'p') return 1;
            if (board[x][y] != '.') return 0;
        }
        return 0;
    }

    int numRookCaptures(vector<vector<char>>& board) {
        int x, y;
        find_rook(board, x, y);
        return
            cap(board, x, y, 0, 1) +
            cap(board, x, y, 0, -1) +
            cap(board, x, y, 1, 0) +
            cap(board, x, y, -1, 0);
    }
};
