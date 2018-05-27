class Solution {
public:
	int to_int(const string& s) {
		if (s[0] == '0' && s.length() > 1) return false;
		if (s.length() > 10) return false;
		long long t = 0;
		for (int i=0;i<s.length();++i) {
			t = t*10 + s[i]-'0';
		}
		if (t >= (1LL<<31)) return false;
		return (int)t;
	}
	int digits(int x) {
		int cnt = 1;
		while(x >= 10) {
			++cnt;
			x/=10;
		}
		return cnt;
	}
	
	
	bool verify(int f1, int f2, int off, string& S, vector<int>& res) {
		res.clear();
		res.push_back(f1);
		res.push_back(f2);
		
		while(off < S.length()) {
			int f = f1+f2;
			int d = digits(f);
			if (off+d > S.length()) return false;
			int t = to_int(S.substr(off, d));
			if (t != f) return false;
			f1 = f2;
			f2 = f;
			res.push_back(f);
			off += d;
		}
		return res.size() > 2;
	}

    vector<int> splitIntoFibonacci(string S) {
		vector<int> ans;
		int l = S.length();
        for(int i=1;i<11;++i) {
			if (i > l) continue;
			int f1 = to_int(S.substr(0,i));
			if (f1 == -1) continue;

			for (int j=1;j<11;++j) {
				if (i+j > l) continue;
				int f2 = to_int(S.substr(i,j));
				if (f2 == -1) continue;
				
				if (verify(f1, f2, i+j, S, ans)) {
					return ans;
				}
			}
		}
		return vector<int>();
    }
};