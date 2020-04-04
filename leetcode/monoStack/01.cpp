#include <stack>
#include <vector>
#include <iostream>

using namespace std;

class Solution {
public:
    vector<int> nextExceed(vector<int>& input) {
        stack<int> monoStack;
        vector<int> result(input.size(), -1);

        for(int index = 0; index < input.size(); ++index) {
            int num = input[index];
            //如果当前的元素比栈内的大，则弹出栈顶的元素,计算元素距离
            while(!monoStack.empty() && input[monoStack.top()] < num) {
                result[monoStack.top()] = index - monoStack.top();
                monoStack.pop();
            }
            monoStack.push(index); //栈内记录的是元素的下标索引
        }

        return result;
    }

    void print(vector<int>& input) {
        for(auto it = input.begin(); it != input.end(); ++it) {
            cout << *it << " ";
        }
        cout << endl;
    }
};

int main()
{
    vector<int> input = { 5, 3, 1, 2, 4 };
    Solution sol;

    sol.print(input);
    vector<int> result = sol.nextExceed(input);
    sol.print(result);

    return 0;
}