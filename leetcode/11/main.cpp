#if 0
class Solution {
public:
    int maxArea(vector<int>& height) {
        int max = 0;
        int length = height.size();

        for(int index = 0; index < length-1; ++index) {
            for(int indexj = index+1; indexj < length; ++indexj) {
                int area = min(height[index], height[indexj]);
                area *= (indexj - index);
                if (max < area) {
                    max = area;
                }
            }
        }

        return max;
    }
};
#endif

class Solution {
public:
    int maxArea(vector<int>& height) {
        int max = 0;
        int left = 0; 
        int right = height.size() - 1;

        while(left < right) {
            int leftH = height[left]; //左边高度
            int rightH = height[right]; //右边高低
            int area = min(leftH, rightH) * (right - left);
            if (max < area) {
                max = area;
            }

            if (leftH < rightH) {
                //如果右边比左边高，那么移动左边，和下一个相邻的面积比较
                ++left;
            } else {
                --right;
            }
        }

        return max;
    }
};