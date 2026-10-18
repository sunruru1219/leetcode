class Solution {
public:
    int minSwaps(vector<int>& nums) {
        int n = nums.size();
        vector<pair<int, int>> vec;
        for (int i = 0; i < n; ++i) {
            vec.push_back({nums[i], i});
        }

        sort(vec.begin(), vec.end(), [](auto a, auto b) {
            int a_ = a.first;
            int b_ = b.first;
            int a_sum = 0;
            int b_sum = 0;

            while (a_ > 0) {
                a_sum += a_ % 10;
                a_ /= 10;
            }

            while (b_ > 0) {
                b_sum += b_ % 10;
                b_ /= 10;
            }
            if (a_sum == b_sum) return a.first < b.first;
            return a_sum < b_sum;
        });

        vector<int> cycle(n, -1);
        int ans = 0;
        for (int i = 0; i < n; ++i) {
            if (cycle[i] != -1) continue;
            //cout << i << " ";
            cycle[i] = 1;
            int cnt = 1;
            int next = vec[i].second;
            while (cycle[next] == -1) {
                //cout << next << " ";
                cycle[next] = 1;
                cnt++;
                next = vec[next].second;
            }
            //cout << endl;
            ans += cnt - 1;
        }

        return ans;

    }
};