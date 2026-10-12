class Solution {
public:
    int gcd(int a, int b) {
        if (b == 0)
            return a;
        else
            return gcd(b, a%b);
    }
    void rotate(vector<int>& nums, int k) {
        int n = nums.size();
        int gcd_ = gcd(n, k);
        for (int i = 0; i < gcd_; ++i) {
            int temp = nums[i];
            int j = i;
            while(true) {
                int t = (j-k)%n; // (j-k)%n replace j-th element
                while(t<0) t+=n;
                if (t == i) break;
                nums[j] = nums[t];
                j = t;
            }
            nums[j] = temp;
        }
    }
};