class Solution {
public:
    bool wordPattern(string pattern, string s) {
        unordered_map<char, string> mp;
        unordered_set<string> used;
        
        // 把s根據空格拆解 並依序紀錄下每個string
        stringstream ss(s);
        vector<string> words;
        string str;
        while (ss >> str) words.push_back(str);

        if (pattern.size() != words.size()) return false;

        for (int i = 0; i < pattern.size(); ++i) {

            // pattern[i]有對應到某個words
            if (mp.count(pattern[i])) {
                // 若不是現在這個words[i]
                if (mp[pattern[i]] != words[i]) return false;
            }
            // pattern[i]尚未對應到某個words
            else {
                // 但words[i]已經被對應過
                if (used.count(words[i])) return false;
                
                // 將pattern[i]跟words[i]配對
                mp[pattern[i]] = words[i];
                used.insert(words[i]);
            }
        }
        return true;
    }
};