class Solution {
public:
    int uniqueLetterString(string S) {
        vector<long long> r(S.length(), 0);
        vector<long long> l(S.length(), 0);
        
        vector<int> llast(128, -1);
        vector<int> rlast(128, S.length());
        for(int i=0;i<S.length();++i) {
            l[i] = llast[S[i]]+1;
            llast[S[i]] = i;
        }
        for(int i=S.length()-1;i>=0;--i) {
            r[i] = rlast[S[i]]-1;
            rlast[S[i]] = i;
        }
        
        long long ans = 0;
        for (int i=0;i<S.length();++i) {
            ans += (i-l[i]+1) * (r[i]-i+1);
            ans = ans % 1000000007;
        }
        return (int)ans;
    }
};