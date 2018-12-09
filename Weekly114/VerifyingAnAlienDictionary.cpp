class Solution {
public:
    bool isAlienSorted(vector<string>& words, string order) {
        for (auto& w : words) {
            for (auto& c : w) {
                int p = order.find(c);
                c = 'a'+p;
            }
        }
        string last = words[0];
        for (auto& w : words) {
            if (w < last) return false;
            last = w;
        }
        return true;
    }
};
