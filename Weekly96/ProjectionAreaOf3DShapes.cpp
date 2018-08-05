class Solution {
public:
    int projectionArea(vector<vector<int>>& grid) {
        int cnt = 0;
        vector<int> c1(grid.size()), c2(grid[0].size());
        for(int i=0;i<grid.size();++i) {
            for(int j=0;j<grid[0].size();++j) {
                if (grid[i][j] != 0) ++cnt;
                if (grid[i][j] > c2[j]) c2[j] = grid[i][j];
                if (grid[i][j] > c1[i]) c1[i] = grid[i][j];
            }
        }
        for(int i=0;i<grid.size();++i) {
            cnt += c1[i];
        }
        for(int j=0;j<grid[0].size();++j) {
            cnt += c2[j];
        }
        return cnt;
    }
};
