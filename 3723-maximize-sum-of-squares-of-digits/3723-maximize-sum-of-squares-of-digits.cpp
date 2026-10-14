class Solution {
public:
    string maxSumOfSquares(int num, int sum) {
        if (num * 9 < sum) return "";
        string ans;
        while (sum > 0 && num > 0) {
            ans += '0' + min(sum, 9);
            sum -= min(sum, 9);
            num--;
        }
        while (num > 0) {
            ans += '0';
            num--;
        }

        return ans;
    }
};