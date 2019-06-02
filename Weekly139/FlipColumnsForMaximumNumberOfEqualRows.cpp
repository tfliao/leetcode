class Solution {
public:
    int maxEqualRowsAfterFlips(vector<vector<int>>& matrix) {
        int N = matrix.size();
        int M = matrix[0].size();
        for (int i=0;i<N;++i) {
            if (matrix[i][0] == 1) {
                for (int j=0;j<M;++j) matrix[i][j] = 1-matrix[i][j];
            }
        }
        sort(matrix.begin(), matrix.end());

        int best = 0;
        int cnt = 1;
        for (int i=1;i<N;++i) {
            if (matrix[i] == matrix[i-1]) {
                ++ cnt;
            } else {
                cnt = 1;
            }
            if (cnt > best) {
                best = cnt;
            }
        }
        if (cnt > best) {
            best = cnt;
        }
        return best;
    }
};
