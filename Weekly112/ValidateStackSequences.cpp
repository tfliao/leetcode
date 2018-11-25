class Solution {
public:
    bool validateStackSequences(vector<int>& pushed, vector<int>& popped) {
        vector<int> s;
        int i = 0;
        for (int p : popped) {
            while (s.empty() || s.back() != p) {
                if (pushed.size() == i) return false;
                s.push_back(pushed[i]);
                ++i;
            }
            s.pop_back();
        }
        return true;
    }
};
