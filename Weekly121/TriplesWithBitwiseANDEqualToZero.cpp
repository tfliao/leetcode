class Solution {
public:
    int countTriplets(vector<int>& A) {
        vector<int> dp(1 << 16, 0);

        for (int i=0;i<A.size();++i)
            for (int j=0;j<A.size();++j)
                dp[A[i] & A[j]] ++;

        int cnt = 0;
        for (int k=0;k<A.size();++k) {
            for (int ij = 0; ij < (1<<16); ++ij) {
                if ((ij & A[k]) == 0)
                    cnt += dp[ij];
            }
        }
        return cnt;

    }
};
