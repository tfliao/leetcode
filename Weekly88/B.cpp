class Solution {
public:
    int maxDistToClosest(vector<int>& seats) {
        vector<int> dr(seats.size());
        vector<int> dl(seats.size());
        
        int d = seats.size();
        for(int i=0;i<seats.size();++i) {
            if (seats[i] == 1) {
                d = 0;
            } else {
                dl[i] = ++d;
            }
        }
        d = seats.size();
        for(int i=seats.size()-1;i>=0;--i) {
            if (seats[i] == 1) {
                d = 0;
            } else {
                dr[i] = ++d;
            }
        }
        int mx = 0;
        for (int i=0;i<seats.size();++i) {
            if (seats[i] == 0) {
                int m = min(dl[i], dr[i]);
                mx = max(mx, m);
            }
        }
        return mx;
        
    }
};