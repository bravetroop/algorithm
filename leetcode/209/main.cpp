class Solution {
public:
    int minSubArrayLen(int s, vector<int>& nums) {
        int sum = 0;
        int start = 0;
        int minLen = 0;

        for(int index = 0; index < nums.size(); ++index) {
            sum += nums[index]; //区间累加
            if (sum >= s) {
                //如果大于s, 则从start开始往右计算到index之间的值，每次前移一个
                while (sum >= s) {
                    sum -= nums[start];
                    ++start;
                }
                //start指向当前和小于s的窗口的开始位置，所以要倒退一个索引
                int len = index - (start -1) + 1;

                if (minLen == 0 || minLen > len) {
                    minLen = len;
                }
            }
        }

        return minLen;
    }
};