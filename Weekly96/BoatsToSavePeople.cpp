class Solution {
public:
    int numRescueBoats(vector<int>& people, int limit) {
        int cnt = 0, p = people.size();
        sort(people.begin(), people.end());
        reverse(people.begin(), people.end());

        for(int i=0;i<p;++i) {
            ++cnt;
            if (people[p-1] + people[i] <= limit) --p;
        }
        return cnt;
    }
};
