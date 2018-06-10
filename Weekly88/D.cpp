class Solution {
public:
	struct rec {
		long long x1, x2, y1, y2;
		rec() {}
		rec(const vector<int>& r) {
			x1 = r[0];
			y1 = r[1];
			x2 = r[2];
			y2 = r[3];
		}
	};
	vector<rec> r;
	vector<int> xs ;

	long cover(int x) {
		vector<int> ys;
		map<int, int> yin, yout;
		
		for (const rec& rr : r) {
			if (rr.x1 <= x && rr.x2 > x) {
				ys.push_back(rr.y1);
				ys.push_back(rr.y2);
				yin[rr.y1] ++;
				yout[rr.y2] ++;
			}
		}
		sort(ys.begin(), ys.end());
		
		int cnt = 0;
		long l = 0;
		int last = 0;
		for (int y : ys) {
			if (cnt == 0) {
				last = y;
			}
			if (yin[y] > 0) {
				++ cnt;
				--yin[y];
			} else {
				-- cnt ;
				--yout[y];
			}
			if (cnt == 0) {
				l += y - last;
			}
		}
		return l;
	}

	long long scan() {
		int last = 0;
		long long c = 0;
		long long area = 0;
		for (int x : xs) {
			area += (x - last) * c;
			c = cover(x);
			last = x;
		}
		return area % (1000000007);
	}
	
    int rectangleArea(vector<vector<int>>& rectangles) {

		for(const auto& rr : rectangles) r.push_back(rec(rr));
		for(const auto& rr : r) {
			xs.push_back(rr.x1);
			xs.push_back(rr.x2);
		}
		sort(xs.begin(), xs.end());
		int p = 1;
		for (int i=1;i<xs.size();++i) {
			if (xs[i] != xs[i-1]) xs[p++] = xs[i];
		}
		xs.resize(p);
		
		return scan();
    }
};