class Solution {
public:
    bool test(const vector<string>& A) {
        for (int i=1;i<A.size();++i) {
            if (A[i-1] > A[i]) return false;
        }
        return true;
    }


    int minDeletionSize(vector<string>& A) {
        vector<string> last(A.size());
        vector<string> next;
        int len = A[0].length();
        int cnt = 0;
        for (int i=0;i<len;++i) {
            next = last;
            for (int j=0;j<A.size();++j) {
                next[j] += A[j][i];
            }
            if (test(next)) {
                last = next;
            }
        }
        return len - last[0].length();
    }
};
