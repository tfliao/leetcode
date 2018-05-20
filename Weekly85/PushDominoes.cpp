class Solution {
public:
	const int INF = 10000000;

    string pushDominoes(string d) {
		vector<int> rcnt(d.length(), INF);
		vector<int> lcnt(d.length(), INF);
		int cnt = INF;
		for(int i=0;i<d.length();++i) {
			if (d[i] == 'R') {
				cnt = 0;
			} else if (d[i] == 'L') {
				cnt = INF;
			} else {
				rcnt[i] = ++cnt;
			}
		}
		cnt = INF;
		for(int i=d.length()-1;i>=0;--i) {
			if (d[i] == 'L') {
				cnt = 0;
			} else if (d[i] == 'R') {
				cnt = INF;
			} else {
				lcnt[i] = ++cnt;
			}
		}
		for(int i=0;i<d.length();++i) {
			if (d[i] == '.') {
				if (rcnt[i] < lcnt[i]) {
					if (rcnt[i] < INF)
						d[i] = 'R';
				} else if (rcnt[i] > lcnt[i]) {
					if (lcnt[i] < INF) 
						d[i] = 'L';
				}
				
			}
		}
		
        return d;
    }
};