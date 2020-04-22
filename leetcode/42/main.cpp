class Solution {
public:
    int trap(vector<int>& height) {
        int result = 0;
        stack<int> monoStack;

        for(int index = 0; index < height.size(); ++index) {
            //单调递减栈，需要思考一个元素导致单调性改变后的问题
            while(monoStack.size() && height[index] > height[monoStack.top()]) {
                int h = height[monoStack.top()];
                monoStack.pop();
                if(monoStack.empty()) {
                    break;
                }
                int width = index - monoStack.top() - 1;
                //连续区域分多次计算，每次只向前计算一块区域，然后累加
                int minH = min(height[index], height[monoStack.top()]) - h;
                result += minH * width;
            }
            monoStack.push(index);
        }

        return result;
    }
};