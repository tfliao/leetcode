class Solution {
public:
    
    int calc(const vector<int>& NN, int len) {
        int res = 0;
        for (int i=0;i<len;++i) {
            int cnt = 0;
            for (int n : NN) {
                if (n & (1<<i)) {
                    ++ cnt;
                }
            }
            if (cnt < NN.size()-cnt) {
                cnt = NN.size()-cnt;
            }
            res += (1<<i) * cnt;
        }
        return res;
    }
    
    int matrixScore(vector<vector<int>>& A) {
        int len = A[0].size();
        int best = 0;
        vector<int> N;
        for(vector<int>& a : A) {
            int n = 0;
            for(int aa : a) {
                n = ((n << 1) | aa);
            }
            N.push_back(n);
        }
        int MSB = (1<<(len-1));
        for(int i=0;i<N.size();++i) {
            if (!(N[i] & MSB)) {
                N[i] = (~N[i] & ((1<<len)-1));
            }
        }
        return calc(N, len);
    }
};