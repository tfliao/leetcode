class Solution {
public:
    string merge(string& a, string &b) {
        sort(b.begin(), b.end());
        string o;
        int i, j;
        for (i=0, j=0; i<a.length() && j < b.length();) {
            if (a[i] == b[j]) {
                o.push_back(a[i]);
                ++i,++j;
            } else if (a[i] < b[j]) {
                ++i;
            } else {
                ++j;
            }
        }
        return o;
    }

    vector<string> commonChars(vector<string>& A) {
        string s = A[0];
        sort(s.begin(), s.end());
        for (auto& a:A) {
            s = merge(s, a);
        }
        vector<string> res;
        for (char c : s) {
            res.push_back(string());
            res.back() += c;
        }
        return res;
    }
};
