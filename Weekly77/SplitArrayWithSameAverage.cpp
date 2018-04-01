class Solution {
public:
    vector<vector<int>> m ;
//    bool m[31][30*10000];
    
    int build(const vector<int>& A) {
        int S = 0;
        for (int a : A) S += a;
        m = vector<vector<int>> (A.size() + 1, vector<int>(S+1, 0));
//        memset(m, 0, sizeof(m));
        m[0][0] = 1;
        int s = 0;
        int n = 0;
        for (int a : A) {
            for (int i=s;i>=0;--i) {
                for (int j=n;j>=0;--j) {
                    if (m[j][i]) m[j+1][i+a] = 1;
                }
            }
            ++n, s += a;
        }
        return s;
    }
    
    bool splitArraySameAverage(vector<int>& A) {
        int S = build(A);
        for (int i=1;i<A.size()-1;++i) {
            if (S * i % A.size() == 0) {
                int ps = S * i / A.size();
                if (m[i][ps]) return true;
            }
        }
        return false;
    }
};
