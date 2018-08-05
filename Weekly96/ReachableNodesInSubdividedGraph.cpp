#define INF (1LL << 40)
vector< vector<pair<int,int>> > G;
vector< long long > cost ;
unordered_set<int> nv;

class Solution {
public:
        
    int reachableNodes(vector<vector<int>>& edges, int M, int N) {
        G.clear();
        G.resize(N);
        for(const auto& E : edges) {
            G[E[0]].push_back(make_pair(E[1],E[2]+1));
            G[E[1]].push_back(make_pair(E[0],E[2]+1));
        }
        cost.clear();
        cost.resize(N);
        nv.clear();
        for(int i=0;i<N;++i) {
            nv.insert(i);
            cost[i] = INF;
        }
        
        cost[0] = 0;
        while (!nv.empty()) {
            int selected = 0;
            long long best = INF;
            for (const auto& p : nv) {
                if (cost[p] < best) {
                    best = cost[p];
                    selected = p;
                }
            }
            if (best > M) break;
            nv.erase(selected);
            for(const auto & e : G[selected]) {
                if(cost[selected] + e.second < cost[e.first]) {
                    cost[e.first] = cost[selected] + e.second;
                }
            }
        }
        for(int i=0;i<N;++i) 
            cout << cost[i] << endl;
        int cnt = 0;
        for(int i=0;i<N;++i) {
            if (cost[i] <= M) ++cnt;
        }
        for(const auto& E : edges) {
            int right = max(0LL, min((long long)E[2], (M - cost[E[0]])));
            int left = max(0LL, min((long long)E[2], (M - cost[E[1]])));
            cnt += min(right + left, E[2]);
        }
        return cnt;
        
    }
};
