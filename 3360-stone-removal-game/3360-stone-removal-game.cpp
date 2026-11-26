class Solution {
public:
    bool canAliceWin(int n) {
        int take = 10;
        bool ans = false;
        while (true) {
            if (n < take) return ans;
            n -= take;
            take--;
            ans = !ans;
        }
        return true;
    }
};