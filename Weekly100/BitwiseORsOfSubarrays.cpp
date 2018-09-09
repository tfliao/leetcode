
unordered_set<int> sol;

#define INF 65536

class Solution {
public:
    vector<vector<int>> next;

    void build_table(vector<int>& A) {
        vector<int> p(32, INF);
        for (int i=A.size()-1;i>=0;--i) {
            next[i] = p;
            for(int b = 0; b < 32; ++b) {
                if (A[i]&(1<<b)) {
                    p [b] = i;
                }
            }
        }
    }

    void calc(vector<int>& A) {
        sol.clear();
        for (int i=0;i<A.size();++i) {
            int p = i;
            int o = A[i];
            sol.insert(o);
            while (p != INF) {
                int c = INF;
                for (int b=0;b<32;++b) {
                    if (!(o & (1<<b)) && next[p][b] < c) {
                        c = next[p][b];
                    }
                }
                if (c == INF) break;
                o |= A[c];
                sol.insert(o);
                p = c;
            }
        }
    }

    int subarrayBitwiseORs(vector<int>& A) {
        int len = A.size();
        next = vector<vector<int>>(len, vector<int>(32, 0));
        build_table(A);
        calc(A);
        return sol.size();

    }
};
