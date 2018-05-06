class Solution {
public:
    vector<vector<int>> largeGroupPositions(string S) {
        vector<vector<int>> ret ;
        int cnt = 0;
        char last = 0;
        for(int i=0;i<=S.length();++i) {
            if (S[i] == last) {
                ++cnt;
            } else {
                if (cnt >= 3) {
                    vector<int> entry;
                    entry.push_back(i - cnt);
                    entry.push_back(i - 1);
                    ret.push_back(entry);
                }
                last = S[i];
                cnt = 1;
            }
        }
        return ret;
    }
};