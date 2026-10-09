class Solution {
public:
    int minInsertions(string s) {
        int cnt = 0, balance = 0;

        for (int i = 0; i < s.size(); ++i) {
            if (s[i] == '(') {
                balance += 2;

                // a single ')' before '('
                if (balance % 2 == 1) {
                    // insert a ')'
                    cnt++;
                    balance--;
                }
            }
            else {
                balance--;

                if (balance < 0) {
                    // insert a '('
                    cnt++;
                    balance += 2;
                }
            }
        }
        return cnt + balance;        
    }
};