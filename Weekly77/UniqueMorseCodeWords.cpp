class Solution {
public:
    char m[26][10] = {".-","-...","-.-.","-..",".","..-.","--.","....","..",".---","-.-",".-..","--","-.","---",".--.","--.-",".-.","...","-","..-","...-",".--","-..-","-.--","--.."}; 
    int uniqueMorseRepresentations(vector<string>& words) {
        int cnt = 0;
        set<string> s ;
        for (string w : words) {
            string code = "";
            for (char c : w) {
                code += m[c-'a'];
            }
            if (s.count(code) == 0) {
                ++ cnt;
            }
            s.insert(code);
        }
        return cnt;
    }
};
