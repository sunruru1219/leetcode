class Solution {
public:
    long long minSumSquareDiff(vector<int>& nums1, vector<int>& nums2, int k1, int k2) {
        //第二版: 使用vector來記錄差值的數量
        //因為插值為0~10000 可直接建立大小為100001的vector
        int n = nums1.size();
        vector<int> diff(100001, 0);

        for (int i = 0; i < n; ++i) {
            diff[abs(nums1[i] - nums2[i])]++;
        }

        long long k = k1 + k2;

        for (int i = 100000; i > 0; --i) {
            int cnt;
            if (diff[i] < k) cnt = diff[i];
            else cnt = k;
            diff[i] -= cnt;
            diff[i - 1] += cnt;
            k -= cnt;
            if (k == 0) break;
        }

        long long ans = 0;
        for (int i = 1; i <= 100000; ++i) {
            ans += (long long)i * i * diff[i];
        }

        return ans;
    }
};
/*
第一版: 使用map來維護每種插值有幾個
map的搜尋.插入.刪除較耗時
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
*/