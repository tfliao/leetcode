class StockSpanner {
public:
    vector<int> p;
    vector<int> last;

    StockSpanner() {
        p.push_back(2147483647);
        last.push_back(-1);
    }

    int next(int price) {
        int l = p.size()-1;

        p.push_back(price);

        while (p[l] <= price) {
            l = last[l];
        }
        last.push_back(l);
        return p.size() - 1 - l;
    }
};

/**
 * Your StockSpanner object will be instantiated and called as such:
 * StockSpanner obj = new StockSpanner();
 * int param_1 = obj.next(price);
 */
