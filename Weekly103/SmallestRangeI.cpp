class Solution {
public:
    int smallestRangeI(vector<int>& A, int K) {
        int mx = *max_element(A.begin(), A.end());
        int mn = *min_element(A.begin(), A.end());

        if (mx - K <= mn + K) return 0;
        else return (mx - K) - (mn + K);


    }
};
