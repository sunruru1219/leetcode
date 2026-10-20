class Solution {
public:
    bool canConstruct(string ransomNote, string magazine) {
        vector<int> mag(26, 0);

        for (char c : magazine) mag[c - 'a']++;

        for (char c : ransomNote) {
            if (mag[c - 'a'] == 0) return false;
            mag[c - 'a']--;
        }

        return true;
    }
};