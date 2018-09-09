class RLEIterator {
public:
    long long p, r;
    vector<long long> cnt;
    vector<long long> value;

    RLEIterator(vector<int> A) {
        p = -1;
        r = 0;
        for(int i=0;i<A.size();i+=2) {
            cnt.push_back(A[i]);
            value.push_back(A[i+1]);
        }
        cnt.push_back((1LL<<60));
        value.push_back(-1);
    }

    int next(int n) {
        while(n > 0) {
            if (r > 0) {
                if (n >= r) {
                    n -= r;
                    r = 0;
                } else {
                    r -= n;
                    n = 0;
                }
            } else {
                ++p;
                r = cnt[p];
            }
            if (n == 0) {
                return value[p];
            }
        }
        return -1;
    }
};

/**
 * Your RLEIterator object will be instantiated and called as such:
 * RLEIterator obj = new RLEIterator(A);
 * int param_1 = obj.next(n);
 */
