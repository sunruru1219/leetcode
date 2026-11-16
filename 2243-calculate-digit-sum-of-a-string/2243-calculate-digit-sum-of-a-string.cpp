class Solution {
public:
    string digitSum(string s, int k) {
        while (true) {
            int n = s.size();
            if (n <= k) return s;

            string temp;
            int i = 0;
            while (i < n) {
                int sum = 0;
                for (int idx = i; idx < i + k && idx < n; ++idx) {
                    sum += s[idx] - '0';
                }
                temp += to_string(sum);
                i += k;
            }
            s = temp;
        }
        return s;
    }
};