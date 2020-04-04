#include <stack>
#include <vector>
#include <iostream>

using namespace std;

#if 0
//暴力解法，求每个值和后面所有可以组成矩形的最大值
class Solution {
public:
    int largestRectangleArea(vector<int>& heights) {
        int max = 0;

        for(int index = 0; index < heights.size(); ++index) {
            int minH = -1;
            int area = 0;
            for(int indexj = index; indexj < heights.size(); ++indexj) {
                if (minH == -1 || minH > heights[indexj]) {
                    minH = heights[indexj];
                }
                if (area < minH * (indexj - index + 1)) {
                    area = minH * (indexj - index + 1);
                }
            }

            if (max < area) {
                max = area;
            }
        }

        return max;
    }
};
#endif

//求最大面积的，可以使用单调栈来完成，
class Solution {
public:
    int largestRectangleArea(vector<int>& heights) {
        
    }
};

int main()
{
    Solution sol;
    sol.largestRectangleArea();

    return 0;
}