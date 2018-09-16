class Solution {
public:
	typedef long long LL;

	bool palindrome(string s) {
		return s == string(s.rbegin(), s.rend());
	}

	LL lb;
	LL ub;
	
	bool check(LL base) {
		LL val = base * base;
		string sval = to_string(val);
		if (palindrome(sval)) {
			if (val >= lb && val <= ub) {
				return true;
			}
		}
		return false;
	}
	
    int superpalindromesInRange(string L, string R) {
        lb = stoll(L);
		ub = stoll(R);
		
		LL limit = sqrt(sqrt(ub)+1)+1;
		
		LL small[] = {1, 4, 9};
		
		int result = 0;
		
		for(int i=0;i<3;++i) {
			if (small[i] <= ub && small[i] >= lb)
				++ result;
		}
		
		for (int i=1;i<=limit;++i) {
			string s = to_string(i);
			string rs = s; reverse(rs.begin(), rs.end());
			
			if (check(stoll(s + rs))) ++ result;
			
			for (int j=0; j<=9; ++j) {
				LL b = stoll(s + to_string(j) + rs);
				if (check(b)) ++ result;
			}
		}
		return result;
    }
};
