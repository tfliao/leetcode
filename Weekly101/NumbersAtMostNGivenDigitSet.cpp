class Solution {
public:
    bool ok;


    int calc(const vector<int>& d, int N, int base, int p) {
        int cnt = 0, i;
        int dd = N / base % 10;
        for (i=0;i<d.size();++i) {
            if (d[i] < dd) cnt += pow(d.size(), p);
            else if (d[i] > dd) {
                ok = false;
                break;
            }
            else {
                break;
            }
        }
        if (i == d.size()) ok = false;
        return cnt;
    }


    int atMostNGivenDigitSet(vector<string>& D, int N) {
        int cnt = 0;
        long long i, base = 10;
        for (i=1;base <= N;++i, base*=10) {
            cnt += pow(D.size(), i);
        }

        vector<int> d;
        for(const auto DD : D) {
            d.push_back(DD[0]-'0');
        }

        ok = true;

        while (ok && i > 0) {
            base /= 10 ;
            -- i;
            cnt += calc(d, N, base, i);
        }
        if (ok) ++cnt;

        return cnt;
    }
};
