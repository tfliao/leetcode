class TimeMap {
public:
    /** Initialize your data structure here. */
    struct Data{
        string value;
        int last;
        int ts;
    };

    vector<Data> d;
    map<string, int> idx;

    TimeMap() {
        d.clear();
        idx.clear();
    }

    int _get(string key, int ts) {
        if (idx.count(key) == 0) {
            return -1;
        }
        int p = idx[key];
        while (p != -1 && d[p].ts > ts) {
            p = d[p].last;
        }
        return p;
    }

    void set(string key, string value, int timestamp) {
        int lt = _get(key, timestamp);
        Data dd = {value, lt, timestamp};
        idx[key] = d.size();
        d.push_back(dd);
    }

    string get(string key, int timestamp) {
        int i = _get(key, timestamp);
        if ( i == -1 ) return "";
        else return d[i].value;
    }
};

/**
 * Your TimeMap object will be instantiated and called as such:
 * TimeMap* obj = new TimeMap();
 * obj->set(key,value,timestamp);
 * string param_2 = obj->get(key,timestamp);
 */
