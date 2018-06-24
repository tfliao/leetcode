class Solution {
public:
    bool buddyStrings(string A, string B) {
        int diff = 0;
        int len = A.length();
        int c1[26] = {0};
        int c2[26] = {0};

        if (len != B.length()) return false;
        
        for(int i=0;i<len;++i) {
            if (A[i] != B[i])
                ++diff;
            c1[A[i]-'a'] ++;
            c2[B[i]-'a'] ++;
        }
        
        bool l2 = false;
        for (int i=0;i<26;++i) {
            if (c1[i] != c2[i])
                return false;
            if (c1[i] >= 2) l2 = true;
        }
        
        if (diff == 2) return true;
        if (diff == 0) return l2;
		return false;
    }
};
