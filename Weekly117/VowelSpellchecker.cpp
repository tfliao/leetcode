class Solution {
public:

    set<string> wl;
    map<string, string> cap;
    map<string, string> nov;

    string UP(const string& w) {
        string r = w;
        for (int i=0;i<r.length();++i) {
            r[i] = toupper(r[i]);
        }
        return r;
    }
    set<char> V;
    string NV(const string& w) {
        string r ;
        for (int i=0;i<w.length();++i) {
            char c = toupper(w[i]);
            if (V.count(c) != 0) {
                r += '-';
            } else {
                r += c;
            }
        }
        return r;
    }


    void make_list(const vector<string> & wordlist) {
        wl.clear();
        cap.clear();
        nov.clear();
        for (const string& w : wordlist) {
            wl.insert(w);
            if (cap.count(UP(w)) == 0)
                cap[UP(w)] = w;
            if (nov.count(NV(w)) == 0)
                nov[NV(w)] = w;
        }
    }

    vector<string> spellchecker(vector<string>& wordlist, vector<string>& queries) {
        V.insert('A'); V.insert('E');
        V.insert('O'); V.insert('I');
        V.insert('U');


        make_list(wordlist);
        vector<string> res;
        for (const string& q : queries) {
            if (wl.count(q) != 0) res.push_back(q);
            else if (cap.count(UP(q)) != 0) {
                res.push_back(cap[UP(q)]);
            } else if (nov.count(NV(q)) != 0) {
                res.push_back(nov[NV(q)]);
            } else {
                res.push_back("");
            }
        }
        return res;
    }
};
