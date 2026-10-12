class Solution {
public:
    vector<string> fullJustify(vector<string>& words, int maxWidth) {
        int n = words.size();
        int i = 0;
        vector<string> ans;

        while (i < n) {
            int j = i;
            int linelen = 0;
            while (j < n && linelen + words[j].size() + (j-i) <= maxWidth) {
                linelen += words[j].size();
                j++;
            }

            int gaps = j - i -1;
            int spaces = maxWidth - linelen;
            string str = "";

            if (j == n || gaps == 0) {
                for (int k = i; k < j; ++k) {
                    if (str.size() > 0) str += " ";
                    str += words[k];
                }
                str += string(maxWidth - str.size(), ' ');
            }
            else {
                int base = spaces / gaps;
                int extra = spaces % gaps;
                for (int k = i; k < j; ++k) {
                    if (str.size() > 0) {
                        if (extra > 0) {
                            str += string(base + 1, ' ');
                            extra--;
                        }
                        else {
                            str += string(base, ' ');
                        }
                    }
                    str += words[k];
                }
            }
            ans.push_back(str);
            i = j;
        }
        return ans;
    }
};