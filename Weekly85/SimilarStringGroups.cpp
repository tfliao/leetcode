class Solution {
public:
	bool similar(const string& S1, const string& S2) {
		int cnt = 0;
		for(int i=0;i<S1.length() && cnt <= 2;++i) {
			if (S1[i]!=S2[i]) ++cnt;
		}
		return cnt == 2;
	}
	
	vector<int> root;
	
	void merge(int x, int y) {
		int rx = find(x), ry = find(y);
		root[rx] = root[y];
	}
	
	int find(int x) {
		if (root[x] == x) return x;
		return root[x] = find(root[x]);
	}
	
	int numSimilarGroups(vector<string>& A) {
		root = vector<int>(A.size());
		for(int i=0;i<A.size();++i) {
			root[i] = i;
		}
		for(int i=0;i<A.size();++i) {
			for (int j=i+1;j<A.size();++j) {
				if (find(i) == find(j)) continue;
				if (similar(A[i], A[j])) {
					merge(i,j);
					cout << "merge " << i << ',' << j << endl;
				}
			}
		}
		set<int> s;
		for(int i=0;i<A.size();++i) {
			s.insert(find(i));
		}
		return s.size();
    }
};
