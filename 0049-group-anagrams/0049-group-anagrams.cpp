class Solution {
public:
    vector<vector<string>> groupAnagrams(vector<string>& strs) {
        // 將strs[i]另存成s並將其做sorting
        // 如果s已有對應的group number N 則group[i] = N
        // 否則將s對應到一個新的group number M，記錄在mp中(mp[i] = M)且group[i] = M
        // 最後再根據group整理答案
        unordered_map<string, int> mp;
        vector<int> group;
        
        int groupN = 0;
        for (int i = 0; i < strs.size(); ++i) {
            string s = strs[i];
            sort(s.begin(), s.end());

            if (mp.count(s)) group.push_back(mp[s]);
            else {
                mp[s] = groupN;
                group.push_back(groupN);
                groupN++;
            }
        }
        
        vector<vector<string>> ans(groupN);
        for (int i = 0; i < strs.size(); ++i) {
            ans[group[i]].push_back(strs[i]);
        }
        return ans;
    }
};