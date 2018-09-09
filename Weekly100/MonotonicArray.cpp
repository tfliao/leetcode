class Solution {
public:
    bool isMonotonic(vector<int>& A) {
        bool inc = true, dec = true;
        for (int i=1;i<A.size();++i) {
            if (A[i] < A[i-1]) inc = false;
            if (A[i] > A[i-1]) dec = false;
        }
        return inc || dec;
    }
};
