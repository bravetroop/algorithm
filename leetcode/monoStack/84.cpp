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
        int maxArea = 0;
        stack<int> monoStack;

        heights.push_back(0); //最后强迫所有的柱子出栈

        for (int index = 0; index < heights.size(); ++index) {
            //维持一个单调递增的栈,向右扩展的时候，遇到第一个减少的数，则依次向前计算，当前高度的柱子面积
            while(!monoStack.empty() && heights[monoStack.top()] > heights[index]) {
                int h = heights[monoStack.top()];
                monoStack.pop();
                
                int subIndex = 0;
                if (monoStack.size()) {
                    //前一个索引到当前索引之间的区域都可以勾勒出该高度
                    subIndex = monoStack.top();
                } else {
                    //之前栈中的最低高度的柱子，其宽度是之前整个的宽度
                    subIndex = -1;
                }

                maxArea = max(maxArea, h * (index - subIndex - 1));
            }
            monoStack.push(index);
        }

        return maxArea;
    }
};

int main()
{
    Solution sol;

    vector<int> heights = { 2,1,5,6,2,3 };

    cout << sol.largestRectangleArea(heights) << endl;

    return 0;
}