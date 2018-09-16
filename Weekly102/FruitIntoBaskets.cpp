class Solution {
public:
    int totalFruit(vector<int>& tree) {
        map<int, int> last;
        int first[2] = {0, 0};
        int b[2] = {-1, -1};
        int best = 0;

        last[-1] = 0;

        for (int i=0;i<tree.size();++i) {
            if (b[0] == tree[i] || b[1] == tree[i]) {
                // do nothing
            } else if (b[0] == -1 || last[b[0]] < last[b[1]]) {
                if (first[1] < last[b[0]]) {
                    first[1] = last[b[0]] + 1;
                }
                b[0] = tree[i];
                first[0] = i;
            } else { // if (b[1] == -1 || last[b[1]] <= last[b[0]]) {
                if (first[0] < last[b[1]]) {
                    first[0] = last[b[1]] + 1;
                }
                b[1] = tree[i];
                first[1] = i;
            }
            last[tree[i]] = i;

            int len = i - min(first[0], first[1]) + 1;
            if (len > best) {
                best = len;
            }
        }
        return best;

    }
};
