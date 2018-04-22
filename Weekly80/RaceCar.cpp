#include <map>
#include <queue>
#include <iostream>
using namespace std;

class Solution {
public:
	typedef pair<int,int> state; // pos, speed
	
	state next(const state& s, char op) {
		if (op == 'A') {
			return state(s.first+s.second, s.second * 2);
		} else { // R
			return state(s.first, (s.second > 0?-1:1) );
		}
	}
    int racecar(int target) {
		char ops[3] = "AR";
		map< state, int > cost;
		queue< state > Q;

		Q.push( state(0, 1) );
		cost[state(0, 1)] = 0;
		while (!Q.empty()) {
			state s = Q.front(); Q.pop();

			int cs = cost[s];

//			if (cs > 5) break;

			for (int i=0;i<2;++i) {
				char op = ops[i];
				state ns = next(s, op);
				if (ns.first == target) return cs + 1;
				if (ns.first < 0) continue;
				if (cost.count(ns) > 0) continue;
				if (ns.second > target*3/2) continue;
//				cout << s.first << ", " << s.second << ": " << cs << " -" << op << "> "  << ns.first << ", " << ns.second<< endl;
				Q.push(ns);
				cost[ns] = cs + 1;
			}
		}
		return -1;
    }
};

int main()
{
	Solution S;
	int target = 3;
//	while (cin >> target) {
	cout << S.racecar(target) << endl;
//	cout << S.racecar2(target) << endl;
//	}
}
