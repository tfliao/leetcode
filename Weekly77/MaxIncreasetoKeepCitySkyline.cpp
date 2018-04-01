class Solution {
public:
    int maxIncreaseKeepingSkyline(vector<vector<int>>& grid) {
        vector<int> v = vector<int>(grid.size(), 0);
        vector<int> c = vector<int>(grid[0].size(), 0);
        
        for (int i=0;i<grid.size();++i) {
            for (int j=0;j<grid[0].size();++j) {
                if (grid[i][j] > v[i]) v[i] = grid[i][j];
                if (grid[i][j] > c[j]) c[j] = grid[i][j];
                
            }
        }
        
        int cnt = 0;
        
        for (int i=0;i<grid.size();++i) {
            for (int j=0;j<grid[0].size();++j) {
                int h = min(v[i], c[j]);
                cnt += h- grid[i][j];
            }
        }
        
        return cnt;
    }
};
