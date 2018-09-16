class Solution {
public:
    vector<int> sortArrayByParity(vector<int>& A) {
        vector<int> res;
        for (int a : A) if (a%2 == 0) res.push_back(a);
        for (int a : A) if (a%2 == 1) res.push_back(a);
        return res;
    }
};
