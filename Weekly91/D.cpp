class Solution {
public:
    vector<int> s;

    bool check(int limit, int K) {
        int head = 0;
        for(int i=1;i<s.size();++i) {
            while (i-head > limit || s[i] - s[head+1] > s[i] - s[head]) {
                ++head;
                if (head >= i) break;
            }
            
            if (s[i] - s[head] >= K) {
                return true;
            }
        }
        return false;
    }
    
    int shortestSubarray(vector<int>& A, int K) {
        s.clear();
        s.push_back(0);
        for(int a:A) { s.push_back(s.back()+a); }
        
        int l = 0, h = A.size() + 2;
        while (h > l+1) {
            int m = (l+h)/2;
            bool r = check(m, K);
//            printf("(%d, %d, %d), r=%d\n", l, m, h, r);
            if (r)
                h = m;
            else
                l = m;
        }
        if (h > A.size()) h = -1;
        return h;
    }
};