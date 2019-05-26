class Solution {
public:
    string removeDuplicates(string S) {
        string r;
        for (char c : S) {
            if (r.empty()) {
                r.push_back(c);
            } else if (r.back() == c) {
                r.pop_back();
            } else {
                r.push_back(c);
            }
        }
        return r;
    }
};
