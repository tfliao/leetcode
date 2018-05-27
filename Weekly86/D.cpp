/**
 * // This is the Master's API interface.
 * // You should not implement it, or speculate about its implementation
 * class Master {
 *   public:
 *     int guess(string word);
 * };
 */
class Solution {
public:
	int check(const string& S1, const string& S2) {
		int cnt = 0;
		for (int i=0;i<6;++i) {
			if (S1[i] == S2[i]) ++ cnt;
		}
		return cnt;
	}

    void findSecretWord(vector<string>& wordlist, Master& master) {
		for (int i=0;i<10;++i) {
			int idx = rand() % wordlist.size();
			string target = wordlist[idx];
			int r = master.guess(target);
			if (r == 6) return;
			
			vector<string> newlist;
			for (string s : wordlist) {
				if (check(s, target) == r) {
					newlist.push_back(s);
				}
			}
			wordlist = newlist;
		}
    }
};