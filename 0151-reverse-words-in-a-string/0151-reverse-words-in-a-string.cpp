class Solution {
public:
    string reverseWords(string s) {
        string result = "";
        for (int i = s.size()-1; i >= 0; --i) {
            while (i >= 0 && s[i] == ' ') {
                --i;
            }
            if (i < 0) {
                return result;
            }

            int end = i;
            while (i >= 0 && s[i] != ' ') {
                --i;
            }
            int start = i+1;
            if (!result.empty()) result += " ";
            result += s.substr(start, end-start+1);
        }
        return result;
    }
};