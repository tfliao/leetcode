#include <iostream>
#include <sstream>
#include <string>
#include <vector>
#include <cstring>
#include <cstdlib>
using namespace std;

class Solution {
public:
	bool allzero(const string& s) {
		for (char c : s)
			if (c != '0') return false;
		return true;
	}

	vector<string> all_possible(const string& s) {
		vector<string> result;
		if (s.length() > 1 && allzero(s))
			return result;
		if (s[0] != '0' || s.length() == 1) {
			result.push_back(s);
		}
		if (s.back() == '0')
			return result;
		
		for (int i=1;i<s.length();++i) {
			if (i > 1 && s[0] == '0') break;
			char buf[32];
			sprintf(buf, "%s.%s", s.substr(0, i).c_str(), s.substr(i, s.length()-i).c_str());
			result.push_back(buf);
		}
		return result;
	} 

    vector<string> ambiguousCoordinates(string S) {
		vector<string> result ;
		int len = S.length()-2;
        for (int i=1;i<S.length()-2;++i) {
			vector<string> left, right;
			left = all_possible(S.substr(1, i));
			right = all_possible(S.substr(i+1, len-i));
			
			for (const string& l : left) {
				for (const string& r : right) {
					char buf[32];
					sprintf(buf, "(%s, %s)", l.c_str(), r.c_str());
					result.push_back(string(buf));
				}
			}
		}
		return result;
    }
};

int main()
{
	Solution S;
	string in = "(00011)";
	vector<string> ans = S.ambiguousCoordinates(in);
	
	for (auto& a : ans) {
		cout << a << endl;
	}
	
}
