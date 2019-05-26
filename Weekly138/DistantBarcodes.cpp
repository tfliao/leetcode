class Solution {
public:
    vector<int> rearrangeBarcodes(vector<int>& B) {
        map<int,int> cnt;
        for (int b : B) {
            cnt[b] ++;
        }
        vector<pair<int,int>> cp;
        for (auto& it : cnt) {
            cp.push_back(make_pair(it.second, it.first));
        }
        sort(cp.begin(), cp.end());
        reverse(cp.begin(), cp.end());
        int idx = 0;
        for (auto& c : cp ) {
            for (int i=0;i<c.first;++i) {
                B[idx++] = c.second;
            }
        }

        vector<int> result(B.size());
        for (int i=0;i<B.size();++i) {
            int idx = i * 2;
            if (idx >= B.size()) {
                idx = idx - B.size() + (B.size()%2 == 0?1: 0);
            }
            result[idx] = B[i];

        }
        return result;
    }
};
