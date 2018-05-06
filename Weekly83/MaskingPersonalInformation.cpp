class Solution {
public:
    
    string handleEmail(string S) {
        int p = S.find('@');
        string name;
        name.push_back((char)tolower(S[0]));
        name.append("*****");
        name.push_back((char)tolower(S[p-1]));
        
        for (int i=p;i<S.length();++i) {
            name.push_back((char)tolower(S[i]));
        }
        
        return name;
    }
    
    string handlePhone(string S) {
        string tmp;
        for (char c : S) {
            if (c <= '9' && c >= '0') tmp.push_back(c);
        }
        if (tmp.length() == 10) {
            return "***-***-" + tmp.substr(tmp.length()-4);
        } else {
            return "+" + string(tmp.length()-10, '*') + "-***-***-" + tmp.substr(tmp.length()-4);
        }
    }
    string maskPII(string S) {
        if (S.find('@') != string::npos) {
            return handleEmail(S);
        } else {
            return handlePhone(S);
        }
    }
};