class Solution {
public:
    int minHeightShelves(vector<vector<int>>& books, int WW) {
        map<pair<int,int>, int> last, next;
        last[make_pair(0, 0)] = 0;
        for (int i=0;i<books.size();++i) {
            int W = books[i][0];
            int H = books[i][1];
            for (auto& it : last) {
                int last_h = it.first.first;
                int remain = it.first.second;
                int total_h = it.second;


                // new row:
                int nH = H, nW = WW - W;
                int nV;
                int& v = next[make_pair(nH, nW)];
                if (v == 0 || total_h + H < v) {
                    v = total_h + H;
                }

                // together
                if (remain >= W) {
                    if (H > last_h) {
                        nH = H;
                        nV = total_h - last_h + H;
                    } else {
                        nH = last_h;
                        nV = total_h;
                    }
                    nW = remain - W;
                    int& v = next[make_pair(nH, nW)];
                    if (v == 0 || nV < v) {
                        v = nV;
                    }
                }
            }
            last = next;
            next.clear();
        }
        int best = 1000*1000;
        for (auto& it : last) {
            int total_h = it.second;
            if (total_h < best) best = total_h;
        }
        return best;
    }
};
