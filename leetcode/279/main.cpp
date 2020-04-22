#if 0
class Solution {
public:
    int get(int n) {
        int mini = n;
        int index = 1;

        if(n == 0) {
            return 0;
        }

        //备忘录
        if(result[n] != 0) {
            return result[n];
        }

        //从后计算，距离n为index*index处的数的值再加1即为n处的值
        while(n >= index * index) {
            mini = min(mini, get(n - index * index) + 1);
            ++index;
        }

        result[n] = mini;
        return mini;
    }

    int numSquares(int n) {
        return get(n);
    }
private:
    map<int, int> result;
};
#else
class Solution {
public:
    int numSquares(int n) {
        vector<int> vec(n+1);

        //动态规划,dp[n] = min(dp[n-index*index]) + 1;
        //左边距离n为index*index的最小值 + 1，即为n处的值
        for(int index = 1; index <= n; ++index) {
            int temp = 1;
            int minNum = n;
            while(index >= temp * temp) {
                minNum = min(minNum, vec[index - temp * temp] + 1);
                ++temp;
            }
            vec[index] = minNum;
        }

        return vec[n];
    }
};
#endif