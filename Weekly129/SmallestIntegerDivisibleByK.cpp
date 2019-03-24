class Solution {
public:
    int smallestRepunitDivByK(int K) {
        if (K%2 == 0) return -1;
        set<int> s;
        int r =  0;
        int cnt = 1;
        while ( true ) {
            r = (r*10+1) % K;
            if (r == 0) return cnt;
            if (s.count(r) != 0) return -1;
            s.insert(r);
            ++cnt;
        }
        return -1;
    }
};
