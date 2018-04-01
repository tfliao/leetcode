class Solution {
public:
    vector<string> subdomainVisits(vector<string>& cpdomains) {
        map<string, int> cp;
        
        for (auto pair : cpdomains) {
            istringstream iss(pair);
            int cnt, p = 0;
            string domain;
            iss >> cnt >> domain;
            cp[domain] += cnt;
            while ((p = domain.find('.', p)) != string::npos) {
                ++p;
                cp[domain.substr(p)] += cnt;
//                cout << domain.substr(p) << " " << cnt << endl;
            }
        }
        
        vector<string> result;
        for (auto pair : cp) {
            char buf[128];
            sprintf(buf, "%d %s", pair.second, pair.first.c_str());
            result.push_back(string(buf));
        }
        return result;
    }
};