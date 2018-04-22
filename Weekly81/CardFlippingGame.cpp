class Solution {
public:
    int flipgame(vector<int>& fronts, vector<int>& backs) {
        set<int> bad;
        vector<int> merge; 
        int len = fronts.size();
        for (int i=0;i<len;++i) {
            if (fronts[i] == backs[i]) {
                bad.insert(fronts[i]);
            }
            merge.push_back(fronts[i]);
            merge.push_back(backs[i]);
        }
        sort(merge.begin(), merge.end());
        for (int v : merge) {
            if (bad.count(v) == 0) 
                return v;
        }
        return 0;
    }
};