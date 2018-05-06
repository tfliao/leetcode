class Solution {
public:
    int consecutiveNumbersSum(int N) {
        int cnt = 0;
        int sub = 0;
        for (int d = 0; true; ++d) {
            sub += d;
            if (sub >= N) break;
            if ((N-sub) % (d+1) == 0) ++cnt;
        }
        
        return cnt;
    }
};