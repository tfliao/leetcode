class Solution {
public:
    vector<int> numsSameConsecDiff(int N, int K) {
        map<int, vector<int>> last, next;

        last.clear();
        for(int i=1;i<10;++i)
            last[i].push_back(i);

        for (int i=2;i<=N;++i) {
            next.clear();
            for(int j=0;j<10;++j) {
                if (j-K >= 0) {
                    for (auto a : last[j])
                        next[j-K].push_back(a*10 + (j-K));
                }
                if (j+K < 10 && K != 0) {
                    for (auto a : last[j])
                        next[j+K].push_back(a*10 + (j+K));
                }
            }
            last = next;
        }

        if (N==1)
            return vector<int>({0,1,2,3,4,5,6,7,8,9});
        else {
            vector<int> res;
            for (int i=0;i<10;++i) {
                for (auto a : last[i])
                    res.push_back(a);
            }
              return res;
        }
    }
};
