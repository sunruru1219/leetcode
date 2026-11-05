class Solution {
public:
    int x_;
    void rebalance(multiset<int>& Lset, multiset<int>& Rset, long long& sumL, long long& sumR) {
        // Lset has too many elements
        while (Lset.size() > (x_ + 1) / 2) {
            auto it = prev(Lset.end());
            int n = *it;
            Lset.erase(it);
            sumL -= n;
            sumR += n;
            Rset.insert(n);
        }

        // Rset has too many elements
        while (Lset.size() < (x_ + 1) / 2) {
            auto it = Rset.begin();
            int n = *it;
            Rset.erase(it);
            sumL += n;
            sumR -= n;
            Lset.insert(n);
        }
    }

    long long getCost(multiset<int>& Lset, multiset<int>& Rset, long long& sumL, long long& sumR) {
        int median = *Lset.rbegin();
        return 1LL * median * Lset.size() - sumL
             + sumR - 1LL * median * Rset.size();
    }

    void add(multiset<int>& Lset, multiset<int>& Rset,
                 long long& sumL, long long& sumR, int n) {
        if (Lset.empty() || n <= *Lset.rbegin()) {
            Lset.insert(n);
            sumL += n;
        }
        else {
            Rset.insert(n);
            sumR += n;
        }
    }

    void remove(multiset<int>& Lset, multiset<int>& Rset, long long& sumL, long long& sumR, int n) {
        auto it = Lset.find(n);
        if (it != Lset.end()) {
            Lset.erase(it);
            sumL -= n;
            return;
        }

        it = Rset.find(n);
        if (it != Rset.end()) {
            sumR -= n;
            Rset.erase(it);
        }
    }

    long long minOperations(vector<int>& nums, int x, int k) {
        int n = nums.size();
        x_ = x;
        const long long INF = LLONG_MAX / 2;
        vector<vector<long long>> dp(n + 1, vector<long long>(k + 1, INF));
        vector<long long> cost(n - x + 1, 0);
        dp[0][0] = 0;

        multiset<int> Lset, Rset;
        int windowL = 0, windowR = x;
        long long sumL = 0, sumR = 0;
        for (int i = windowL; i < windowR; ++i) {
            Lset.insert(nums[i]);
            sumL += nums[i];
        }
        rebalance(Lset, Rset, sumL, sumR);
        cost[0] = getCost(Lset, Rset, sumL, sumR);

        windowL++;
        windowR++;
        while (windowR < n + 1) {
            remove(Lset, Rset, sumL, sumR, nums[windowL - 1]);
            rebalance(Lset, Rset, sumL, sumR);
            add(Lset, Rset, sumL, sumR, nums[windowR - 1]);
            rebalance(Lset, Rset, sumL, sumR);
            cost[windowL] = getCost(Lset, Rset, sumL, sumR);

            windowL++;
            windowR++;
        }

        for (int i = 1; i < n + 1; ++i) {
            for (int j = 0; j < k + 1; ++j) {
                dp[i][j] = dp[i - 1][j];

                if (i >= x && j >= 1 && dp[i - x][j - 1] != INF) {
                    dp[i][j] = min(dp[i][j],
                           dp[i - x][j - 1] + cost[i - x]);
                }
            }
        }

        return dp[n][k];
    }
};