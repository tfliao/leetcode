class Solution {
public:
    
    bool test(string S, string word) {
        int i = 1, j = 1;
        if (S[0] != word[0]) return false;
//        cout << S << ", " << word << endl;
        while (i <= S.length() && j <= word.length()) {
//            cout << "compare(i,j) "<< i <<", "<<j << ": " << S[i]  << ", " << word[j] << endl;
            if (S[i] == word[j]) ++i, ++j;
            else {
                if (S[i] != S[i-1]) return false;
                if (S[i] != S[i+1] && (i<2 || S[i]!= S[i-2])) return false;
                while (S[i] == S[i-1]) ++i;
            }
        }
        bool result =  i == S.length()+1 && j == word.length() +1;
//        cout << S << ", " << word << ": " << result << endl;
        return result;
    }
    
    int expressiveWords(string S, vector<string>& words) {
        return count_if(words.begin(), words.end(), [=](string w){ return test(S, w); });
    }
};