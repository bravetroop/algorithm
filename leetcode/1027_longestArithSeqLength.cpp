class Solution {
public:
    int longestArithSeqLength(vector<int>& A) {
        int max = 0;
        int length = A.size();
        vector<unordered_map<int, int>> dp(length);

        dp[0][0] = 1;
        for(int index = 0; index < length; ++index) {
            for(int j = 0; j < index; ++j) {
                int seq = A[index] - A[j]; // 和前面元素的差值

                if (dp[j][seq]) { //如果等差数列前一个元素已经有长度了
                    //dp[index][seq]表示当前元素的等差(seq)数列的长度
                    //等于前一个等差元素的数组长度 + 1
                    dp[index][seq] = dp[j][seq] + 1;
                } else {
                    //A[index]和A[j]第一次组成的等差数列
                    dp[index][seq] = 2;
                }

                if (dp[index][seq] > max) {
                    max = dp[index][seq];
                }
            }
        }

        return max;
    }
};
