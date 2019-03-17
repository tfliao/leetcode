class Solution {
public:

    int f(int m, int d) {
        int r = 1;
        for (int i=0;i<d;++i) r *= (m-i);
        return r;
    }

    int extra(int dgt) {
        int cnt = 0;
        for (int i=0;i<dgt;++i) {
            cnt += 9 * f(9,i);
        }
        return cnt;
    }

    int calc(int N, int base, int dgt) {
        int cnt = 0;
        int choice = 9;
        bool first = true;
        bool mk[10] = {false};


        while (base > 0) {
            int d = N / base % 10;
            int vld = 0;
            for (int i=0;i<d;++i) vld += (mk[i]?0:1);
            if (first) --vld;
            cnt += vld * f(choice, dgt);
            if (mk[d]) {
                // repeated, ignore smaller
                break;
            }
            mk[d] = true;
            first = false;
            base /= 10;
            choice --;
            dgt --;
        }
        if (base == 0) ++ cnt;
        return cnt;
    }

    int numDupDigitsAtMostN(int N) {
        long long base = 1;
        int digit = 0;
        while (N >= base*10) { base *= 10; ++digit; }

        return N - calc(N, base, digit) - extra(digit);
    }
};
