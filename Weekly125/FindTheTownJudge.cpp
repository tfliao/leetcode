class Solution {
public:
    int findJudge(int N, vector<vector<int>>& trust) {
        vector<int> cnt(N+1, 0);
        for (auto a : trust) {
            cnt[a[1]] ++;
            cnt[a[0]] = -N;
        }
        for (int i=1;i<=N;++i) {
            if (cnt[i] == N-1) return i;
        }
        return -1;
    }
};
