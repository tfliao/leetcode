class Solution {
public:
    vector<int> ans;
    vector<vector<int>> edges;

    void draw(int x) {
        if (ans[x] != 0) return;
        bool mark[5] = {false};
        for (int i=0;i<edges[x].size();++i) {
            int p = edges[x][i];
            mark[ans[p]] = true;
        }
        int c;
        for (c=1;c<5;++c) {
            if (!mark[c]) break;
        }
        ans[x] = c;
        for (int i=0;i<edges[x].size();++i) {
            int p = edges[x][i];
            draw(p);
        }
    }

    vector<int> gardenNoAdj(int N, vector<vector<int>>& paths) {
        ans = vector<int>(N, 0);

        edges = vector<vector<int>>(N);
        for(int i=0;i<paths.size();++i) {
            int a = paths[i][0] - 1, b = paths[i][1] - 1;
            edges[a].push_back(b);
            edges[b].push_back(a);
        }
        for (int i=0;i<N;++i) {
            draw(i);
        }

        return ans;
    }
};
