class Solution {
public:
    vector<int> sortArrayByParityII(vector<int>& A) {
        int i = 0, j = 1;
        vector<int> res(A.size(), -1);
        for (auto a:A) {
            if (a % 2 == 0) {
                res[i] = a; i += 2;
            } else {
                res[j] = a; j += 2;
            }
        }
        return res;
    }
};
