class Solution {
public:
    vector<int> maxDepthAfterSplit(string seq) {
        vector<int> result(seq.length());
        int cnt = 0;
        for (int i=0;i<seq.length();++i) {
            char c = seq[i];
            if (c == '(') {
                ++ cnt;
                result[i] = cnt % 2;
            } else {
                result[i] = cnt % 2;
                -- cnt;
            }
        }
        return result;
    }
};
