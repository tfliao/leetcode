class Solution {
public:
    vector<int> distributeCandies(int candies, int num_people) {
        vector<int> res(num_people);
        for (int i=1;candies > 0; ++i) {
            int idx = (i-1) % num_people;
            int cnt = min(candies, i);
            res[idx] += cnt;
            candies -= cnt;
        }
        return res;
    }
};
