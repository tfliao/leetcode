class Solution {
public:
    vector<int> threeEqualParts(vector<int>& A) {
        int l = A.size();
        int zs = 0;
        vector<int> s (l+1);

        for (int i=0;i<l;++i) {
            s[i+1] = s[i] + A[i];
            if (A[i] == 0) ++zs;
            else zs = 0;
        }

        if (s[l] % 3 != 0) return vector<int>({-1,-1});
        if (s[l] == 0) return vector<int>({0,2});
        int n = s[l] / 3;

        int a = -1, b = -1;
        int last = 0;
        int cz = 0;

        for (int i=1;i<=l;++i) {
            if (s[i] - s[last] == n) {
                if (A[i-1] == 0)
                    ++ cz;

                if (cz == zs) {
                    if (a == -1) a = i - 1;
                    else if (b==-1) {
                        b = i;
                        break;
                    }
                    last = i;
                    cz = 0;
                }
            }
        }

        if (a == -1 || b == -1)
            return vector<int>({-1,-1});

        int o = 0;
        while (!(a-o < 0 || b-1-o <= a || l-1-o < b)) {
            if (A[a-o] != A[b-1-o] || A[a-o] != A[l-1-o])
                return vector<int>({-1,-1});
            ++o;
        }
        return vector<int>({a, b});
    }
};
