class Solution {
public:
    int jump(vector<int>& nums) {
        int n = nums.size();
        if (n == 1) return 0;
        int curr_r = nums[0];
        int curr_i = 0;
        int step = 0;
        //if (curr_r >= n-2) return 1; //可以直接從頭跳到尾的狀況
        while(true) {
            //站在curr_i上去找所有可透過curr_r到達的點 尋找可換到最多油的車 跳一步到那個點

            // 如果現在的油量可以直接跳到終點 就回傳step+1
            if (curr_r >= n-1-curr_i) return step+1;
            //先初始化最多油的車載剛好走一步的位置
            int next_i = curr_i+1;
            int max_r = curr_r-1;
            for (int k = 1; k <= nums[curr_i]; ++k) {
                int poss_i = curr_i+k;
                int poss_r = nums[poss_i];
                //判斷在poss_i的位置能不能換到油較多的車
                if (poss_r > curr_r - k && poss_r >= max_r-(poss_i-next_i)) {
                    max_r = poss_r;
                    next_i = poss_i;
                }
            }
            //跳到剛剛找出可以有最多油的車的點
            curr_r = max_r;
            curr_i = next_i;
            step+=1;
        }
        return step;
    }
};