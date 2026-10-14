class Solution {
public:
    string maxSumOfSquares(int num, int sum) {
        if (num * 9 < sum) return "";
        string ans;
        ans.reserve(num);
        while (num > 0) {
            int digit = min(sum, 9);
            ans += '0' + digit;
            sum -= digit;
            num--;
        }
        return ans;
    }
};