class Solution {
public:
    bool isLongPressedName(string name, string typed) {
        int i = 1, j = 1;
        if (name[0] != typed[0]) return false;
        for (; name[i] != 0 || typed[j] != 0;) {
            if (name[i] == typed[j]) {
                ++i, ++j;
            } else if (typed[j] == name[i-1]) {
                ++j;
            } else {
                return false;
            }
        }
        return true;
    }
};
