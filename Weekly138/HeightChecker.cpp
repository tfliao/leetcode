class Solution {
public:
    int heightChecker(vector<int>& heights) {
        vector<int> s = heights;
        sort(s.begin(), s.end());
        int cnt = 0;
        for (int i=0;i<s.size();++i) {
            if (s[i] != heights[i]) ++ cnt;
        }
        return cnt;
    }
};
