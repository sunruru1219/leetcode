class Solution {
public:
    long long minSumSquareDiff(vector<int>& nums1, vector<int>& nums2, int k1, int k2) {
        int n = nums1.size();
        map<long long, long long> diff;
        long long ans = 0;

        for (int i = 0; i < n; ++i) {
            diff[abs(nums1[i] - nums2[i])]++;
        }
        
        long long k = k1 + k2;
        while (k > 0) {
            auto it = diff.rbegin();
            long long d = (*it).first;
            if (d == 0) return 0;
            long long cnt = (*it).second;
            if (k >= cnt) {
                diff[d - 1] += cnt;
                k -= cnt;
                diff.erase(d);
            }
            else {
                diff[d - 1] += k;
                diff[d] -= k;
                break;
            }
        }

        for (auto it : diff) ans += it.first * it.first * it.second;

        return ans;

    }
};