unordered_map<int,int> ss;

class Solution {
public:
    int numSubmatrixSumTarget(vector<vector<int>>& MX, int target) {
        int N = MX.size();
        int M = MX[0].size() + 1;
        for (int i=0;i<N;++i) {
            MX[i].push_back(0);
            int tmp = MX[i][0];
            MX[i][0] = 0;
            for (int j=1;j<MX[i].size();++j) {
                int t2 = MX[i][j];
                MX[i][j] = tmp;
                tmp += t2;
            }
        }
        int cnt = 0;
        for (int q = 1; q < M; ++q) {
            for (int p=0; p< q; ++p) {
                ss.clear();
                ss[0] = 1;
                int S = 0;
                for (int i=0;i<N;++i) {
                    int v = MX[i][q] - MX[i][p];
                    S += v;
                    cnt += ss[S-target];
                    ss[S] ++;
                }
            }
        }
        return cnt;
    }
};
