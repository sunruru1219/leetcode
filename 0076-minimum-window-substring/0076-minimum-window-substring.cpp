class Solution {
public:
    string minWindow(string s, string t) {
        if (s.size() < t.size()) return "";

        unordered_map<char, int> need, window;
        for (char c : t) need[c]++;

        int l = 0, r = 0;
        int required = need.size();
        int formed = 0;
        int minLen = INT_MAX;
        int start = 0;

        while (r < s.size()) {
            char c = s[r];
            window[c]++;
            
            // 若字元c蒐集到需要的數量
            // 則formed + 1
            if (need.count(c) && need[c] == window[c]){
                formed++;
            }

            // 當所有必要的元素都蒐集完
            // 則持續將L向右移動 用以尋找最短且符合條件的substring
            while (l <= r && formed == required) {

                // L ~ R 的長度若小於當前最短
                // 則將最短設為 R - L + 1，起點設為L
                if (r - l + 1 < minLen) {
                    minLen = r - l + 1;
                    start = l;
                }

                // L往右一格，並將window&formed更新
                char d = s[l];
                l++;

                window[d]--;
                // 若導致字元d的數量低於所需
                // 則formed要減1
                if (need.count(d) && window[d] < need[d])
                    formed--;
            }           
            
            // 跳出while則表示當前L ~ R並不滿足需求
            // R向右擴張
            r++;
        }

        if (minLen == INT_MAX) return "";
        return s.substr(start, minLen);
    }
};