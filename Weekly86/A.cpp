class Solution {
public:
	bool verify(const vector<vector<int>>& grid, int x, int y) {
		bool check[16] = {false};
		int sumx[3] = {0}, sumy[3] = {0};
		int sumd1 = 0, sumd2 = 0;
		for(int i=0;i<3;++i) {
			for(int j=0;j<3;++j) {
				int v = grid[x+i][y+j];
				if (v < 1 || v > 9) return false;
				if (check[v]) return false;
				check[v] = true;
				sumx[i] += v;
				sumy[j] += v;
			}
			sumd1 += grid[x+i][y+i];
			sumd2 += grid[x+i][y-i+2];
		}
		if (sumd1 != sumd2) return false;
		for(int i=0;i<3;++i) {
			if (sumd1 != sumx[i]) return false;
			if (sumd1 != sumy[i]) return false;
		}
		return true;
	}


    int numMagicSquaresInside(vector<vector<int>>& grid) {
        int cnt = 0;
		if (grid.size() < 3) return false;
		for (int i=0;i<grid.size()-2;++i) {
			for (int j=0;j<grid[0].size()-2;++j) {
				if(verify(grid, i, j)) ++ cnt;
			}
		}
		return cnt;
    }
};