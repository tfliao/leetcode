class Solution {
public:
    int rev(int l) {
        if (l == 1) return 1;
        else return rev(l/2) * 2 + (1 - l&1);
    }
    int odd(int l) {
        if(l == 1) return true;
        else return !odd(l/2);
    }

    vector<int> res;
    void solv(int l) {
        if (l == 1) {
            res.push_back(l);
        } else {
            solv(l/2);
            if (odd(l)) {
                res.push_back(l);
            } else {
                res.push_back(rev(l));
            }
        }
    }

    vector<int> pathInZigZagTree(int label) {
        res.clear();
        if (!odd(label)) {
            label = rev(label);
        }
        solv(label);
        return res;
    }
};
