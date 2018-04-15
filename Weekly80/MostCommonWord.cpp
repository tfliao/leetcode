class Solution {
private:
	string sanitize( const string& word ) {
		string out;
		for (char c : word) {
			if (isalpha(c)) out += tolower(c);
		}
		return out;
	}
	
	
public:

    string mostCommonWord(string paragraph, vector<string>& banned) {
        map<string, int> cnt;
		istringstream iss(paragraph);
		for (auto & ban : banned) { cnt[ban] = -99999; }

		string word;
		while ( iss >> word ) {
			word = sanitize(word);
			cnt[word] += 1;
		}
		int best = 0;
		string ret = "";
		for (auto& it : cnt) {
			if (it.second > best) {
				ret = it.first;
				best = it.second;
			}
		}
		return ret;
    }
};