class Solution {
public:
    vector<int> numberOfLines(vector<int>& widths, string S) {
        int nl = 0, l = 0;
        for (int i=0;i<S.length();++i) {
            int w = widths[S[i]-'a'];
            if (l < w) {
                nl ++;
                l = 100 - w;
            } else {
                l = l - w;
            }
        }
        return vector<int>({nl, 100-l});
    }
};
