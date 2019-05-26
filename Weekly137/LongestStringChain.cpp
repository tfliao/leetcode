class Solution {
public:
    int N;
    map<int, vector<int>> ws;
    vector<int> dp;

    bool ischild(const string& A, const string& B) {
        int off = 0;
        for (int i=0;i<A.size();++i) {
            while (A[i] != B[i + off]) {
                if (off != 0) return false;
                ++off;
            }
        }
        return true;
    }

    int dfs(int x, const vector<string>& words) {
        if (dp[x] != -1) {
            return dp[x];
        }
        int r = 1;
        int l = words[x].length();
        const vector<int>& c = ws[l+1];
        for (int i=0;i<c.size();++i) {
            if (ischild(words[x], words[c[i]])) {
                int t = dfs(c[i], words) + 1;
                if (t > r) {
                    r = t;
                }
            }
        }
        return dp[x] = r;
    }

    int longestStrChain(vector<string>& words) {
        N = words.size();
        ws.clear();
        dp = vector<int>(N, -1);
        for (int i=0;i<N;++i) {
            ws[words[i].length()].push_back(i);
        }
        int best = 0;
        for (int i=0;i<N;++i) {
            int r = dfs(i, words);
            if (r > best) best = r;
        }
        return best;
    }
};
