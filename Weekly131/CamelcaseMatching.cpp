class Solution {
public:
    bool verify(const string& q, const string& p) {
        int j = 0;
        for (int i=0;i<q.length();++i) {
            if (q[i] == p[j]) {
                ++j;
            } else if (q[i] <= 'Z') {
                return false;
            }
        }
        return p[j] == '\0';
    }

    vector<bool> camelMatch(vector<string>& queries, string pattern) {
        vector<bool> r;
        for (const auto& q : queries) {
            r.push_back(verify(q, pattern));
        }
        return r;
    }
};
