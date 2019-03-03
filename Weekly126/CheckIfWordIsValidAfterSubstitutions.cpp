class Solution {
public:
    bool isValid(string S) {
        string st;
        for (auto c : S) {
            if (c != 'c') {
                st += c;
            } else {
                int l = st.length();
                if (l < 2) return false;
                if (st[l-1] != 'b' || st[l-2] != 'a') return false;
                st.resize(l-2);
            }
        }
        return st.empty();
    }
};
