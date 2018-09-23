class TopVotedCandidate {
public:

    priority_queue<pair<int,int>> pq;
    map<int,int> cnt;
    vector<int> ps;
    vector<int> ts;
    vector<int> ans ;

    TopVotedCandidate(vector<int> persons, vector<int> times)
    {
        ps = persons;
        ts = times ;

        for (int r = 0; r < persons.size();++r) {
            cnt[ps[r]] ++;
            pq.push(make_pair((cnt[ps[r]]*5000 + r), ps[r]));
            ans.push_back(pq.top().second);
        }
    }

    int q(int t) {
        auto it = upper_bound(ts.begin(), ts.end(), t);
        int idx = it - ts.begin() - 1;
        return ans[idx];
    }
};

/**
 * Your TopVotedCandidate object will be instantiated and called as such:
 * TopVotedCandidate obj = new TopVotedCandidate(persons, times);
 * int param_1 = obj.q(t);
 */
