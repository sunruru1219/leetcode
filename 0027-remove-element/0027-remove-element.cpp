class Solution {
public:
    int removeElement(vector<int>& nums, int val) {
        int k = 0;
        int g= 0;
        vector<int> m;
        vector<int> n;

        // 記錄跟val相等的元素的位置
        for (int i = 0; i < nums.size(); i++) {
            if (nums[i] == val) {
                m.push_back(i);
            }
            else {
                k+=1;
                n.push_back(i);
            }
        }

        // 從尾端開始 覆蓋前面跟val相等的元素
        int j = n.size()-1;
        for (int i = 0; i < m.size(); ++i) {
            if (m[i]>=k) break;
            nums[m[i]] = nums[n[j]];
            j-=1;
        }
        return k;
    }
};