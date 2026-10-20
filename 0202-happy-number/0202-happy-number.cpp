class Solution {
public:
    bool isHappy(int n) {
        unordered_set<int> seen;
        
        while (n != 1) {
            int s = 0;
            while (n > 0) {
                s += (n % 10) * (n % 10);
                n /= 10;  
            }
            if (seen.count(s)) return false;
            seen.insert(s);
            n = s;
        }
        return true;
    }
};