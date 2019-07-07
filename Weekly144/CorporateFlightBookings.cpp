class Solution {
public:
    vector<int> corpFlightBookings(vector<vector<int>>& bookings, int n) {
        vector<int> diff(n+2);
        for (auto b : bookings) {
            diff[b[0]] += b[2];
            diff[b[1]+1] -= b[2];
        }
        vector<int> res;
        int cnt = 0;
        for (int i=1;i<=n;++i) {
            cnt += diff[i];
            res.push_back(cnt);
        }
        return res;
    }
};
