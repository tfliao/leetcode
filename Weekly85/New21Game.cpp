#include <vector>
#include <iostream>
using namespace std;

class Solution {
public:
    double new21Game(int N, int K, int W) {
		vector<double> dp;
		double s = 0;
		dp.push_back(1);
		for (int i=0;i<K+W;++i) {
			if (i < K)
				s += dp.back() / W;
			if(i >= W) 
				s -= dp[i-W] / W;
			dp.push_back(s);
		}
		s = 0;
		for (int i=K;i<=N;++i) {
			s += dp[i];
		}
		return s;
    }
};

int main()
{
	int N, K, W;
	while (cin >> N >> K >> W) {
		cout << Solution().new21Game(N, K, W) << endl;
	}
	return 0;
}