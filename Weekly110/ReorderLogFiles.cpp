
bool cmp(const string& s1, const string& s2) {
    string id1, id2, msg1, msg2;
    stringstream ss1(s1);
    stringstream ss2(s2);

    ss1 >> id1; getline(ss1, msg1);
    ss2 >> id2; getline(ss2, msg2);

    if (msg1 != msg2)
        return msg1 < msg2;
    else
        return id1 < id2;
}

class Solution {
public:
    vector<string> reorderLogFiles(vector<string>& logs) {
        vector<string> dlog;
        vector<string> alog;

        for (const string& log : logs) {
            stringstream ss(log);
            string id, l;
            ss >> id >> l;
            if (l[0] <= '9' && l[0] >= '0')
                dlog.push_back(log);
            else
                alog.push_back(log);
        }
        sort(alog.begin(), alog.end(), cmp);
        for (auto l : dlog) {
            alog.push_back(l);
        }
        return alog;

    }
};
