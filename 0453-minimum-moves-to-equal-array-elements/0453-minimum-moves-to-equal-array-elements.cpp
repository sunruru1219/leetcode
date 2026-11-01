class Solution {
public:
    int minMoves(vector<int>& nums) {
        // n - 1 個 +1 等價於 1個 -1
        // 計算每個數需要幾次"-1"來變成最小的數

        int m = nums[0];

        for (int i : nums) {
            m = min(m, i);
        }

        int ans = 0;
        for (int i : nums) {
            ans += i - m;
        }

        return ans;
    }
};

/* brute force
if (nums.size() == 1) return 0;
        if (nums.size() == 2) return abs(nums[0] - nums[1]);
        map<int, int> mp;

        for (int i : nums) {
            if (mp.count(i)) mp[i]++;
            else mp[i] = 1;
        }

        
        int ans = 0;
        while (mp.size() > 1) {
            ans++;
            for (auto it = mp.rbegin(); it != mp.rend(); it++) {
                
                int i = (*it).first;
                int cnt = (*it).second;
                //cout << i << " " << cnt << endl;
                if (mp.count(i + 1)) {
                    mp[i + 1] += cnt;
                }
                else {
                    mp[i + 1] = cnt;
                }
                mp.erase(i);
            }
            //cout << endl;
            // 所有n個數都被+1 但最大的不能+1 所以要扣回來
            auto it = mp.rbegin();
            int MaxNum = (*it).first;
            int MaxNumCnt = (*it).second;
            if (MaxNumCnt > 1) {
                mp[MaxNum]--;
            }
            else {
                mp.erase(MaxNum);
            }
            if (mp.count(MaxNum - 1)) mp[MaxNum - 1]++;
            else mp[MaxNum - 1] = 1;
        }
        return ans;
*/