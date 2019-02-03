/**
 * Definition for an interval.
 * struct Interval {
 *     int start;
 *     int end;
 *     Interval() : start(0), end(0) {}
 *     Interval(int s, int e) : start(s), end(e) {}
 * };
 */
class Solution {
public:
    
    bool intersect(Interval& a, Interval& b, Interval& c) {
        // printf("Checking [%d,%d] vs [%d, %d]\n", a.start, a.end, b.start, b.end);
        if (a.start > b.end || b.start > a.end)
            return false;
        c = Interval(max(a.start, b.start), min(a.end, b.end));
        return true;
    }
    
    vector<Interval> intervalIntersection(vector<Interval>& A, vector<Interval>& B) {
        vector<Interval> ans;
        
        int i = 0, j = 0;
        while (i < A.size() && j < B.size()) {
            Interval c ;
            Interval& a = A[i];
            Interval& b = B[j];
            if (intersect(a, b, c)) {
                ans.push_back(c);
            }
            if (a.end < b.end) {
                ++i;
            } else if (b.end < a.end) {
                ++j;
            } else {
                ++i, ++j;
            }
        
        }
        return ans;
    }
};
