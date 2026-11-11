class Solution {
public:
    long long minimumCost(int cost1, int cost2, int costBoth, int need1, int need2) {
        long long ans = 0;
        if (costBoth > cost1 + cost2) {
            ans += (long long)cost1 * need1;
            ans += (long long)cost2 * need2;
        }
        else {
            ans += (long long)costBoth * min(need1, need2);
            if (need1 > need2) {
                ans += (long long)(need1 - need2) * min(cost1, costBoth);
            }
            else {
                ans += (long long)(need2 - need1) * min(cost2, costBoth);
            }
        }
        return ans;
    }
};