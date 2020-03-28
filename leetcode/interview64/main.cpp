class Solution {
public:
    int sumNums(int n) {
        int sum = 0;
        if(n == 1) {
            return 1;
        }

        sum = n + sumNums(n-1);
        return sum;
    }
};