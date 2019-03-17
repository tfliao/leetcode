class Solution {
public:
    int bitwiseComplement(int N) {
        unsigned m = 2;
        while ( m - 1 < N ) {
            m <<= 1;
        }
        return ~N & (m-1);
    }
};
