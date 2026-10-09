class Solution {
public:
    int minInsertions(string s) {
        int n = s.size();
        int balance = 0;
        int cnt = 0;

        for (int i = 0; i < n; ++i) {
            if (s[i] == '(') balance += 2;
            else {
                balance--;
                if (s[i + 1] == '(') {
                    if (balance > 0) {
                        cnt++;
                        balance--;
                    }
                    else {
                        cnt += 2;
                        balance = 0;
                    }
                }

                else {
                    while (i + 1 < n && s[i + 1] == ')') {
                        i++;
                        balance--;
                    }
                    if (balance < 0) {
                        balance = -balance;
                        cnt += balance / 2 + 2 * (balance % 2);
                        balance = 0;
                    }
                    else if (balance > 0 && balance % 2 == 1) {
                        balance--;
                        cnt++;
                    }
                }
            }
        }
        return cnt + balance;
    }
};
