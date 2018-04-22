class Solution {
public:
    bool inside(const string& s1, const string& s2) {
        if (s1.length() < s2.length())
            return false;
        int d = s1.length() - s2.length();
        if (s1.find(s2, d) != string::npos)
            return true;
        return false;
    }

    int minimumLengthEncoding(vector<string>& words) {
        vector<int> needed(words.size(), 1);
        
        for(int i=0;i<words.size();++i) {
            if (!needed[i]) continue;
            for(int j=0;j<words.size();++j) {
                if (i == j) continue;
                if (!needed[j]) continue;
                if (inside(words[i], words[j])) {
                    needed[j] = 0;
                }
            }
        }
        int cnt = 0;
        for (int i=0;i<words.size();++i) {
            if (needed[i]) {
                cnt += words[i].length() + 1;
            }
        }
        return cnt;
    }
};