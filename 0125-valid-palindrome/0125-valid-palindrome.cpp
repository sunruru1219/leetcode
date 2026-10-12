class Solution {
public:
    bool isValid(char c) {
        return (c >= 'a' && c <= 'z') ||
               (c >= 'A' && c <= 'Z') ||
               (c >= '0' && c <= '9');
    }
    
    bool isPalindrome(string s) {
        int n = s.size();
        int i = 0;
        int j = n - 1;
        while (i < j) {
            while (!isValid(s[i]) && i < j) ++i;
            while (!isValid(s[j]) && i < j) --j;
            if (tolower((unsigned char)s[i]) != tolower((unsigned char)s[j])) return false;
            ++i;
            --j;
        }
        return true;
    }
};