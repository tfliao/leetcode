class Solution {
public:
    vector<int> qt;
    int N;
    vector<vector<int>> poor;
    
    vector<int> ans;
    
    int dfs(int x) {
        if (ans[x] == -1) {
            int a = x;
            for (int c : poor[x]) {
                int v = dfs(c);
                if (qt[v] < qt[a]) a = v;
            }
            ans[x] = a;
        }
        return ans[x];
    }
    
    void solv() {
        for(int i=0;i<N;++i) {
            if (ans[i] == -1) {
                dfs(i);
            }
        }
    }
    
    vector<int> loudAndRich(vector<vector<int>>& richer, vector<int>& quiet) {
        N = quiet.size();
        qt = quiet;
        poor = vector<vector<int>>(N);
        ans = vector<int>(N, -1);
        for(const auto& rich : richer) {
            int x = rich[0], y = rich[1];
            poor[y].push_back(x);
        }
        
        solv();
        
        return ans;
    }
};