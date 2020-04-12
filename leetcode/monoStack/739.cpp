class Solution {
public:
    vector<int> dailyTemperatures(vector<int>& T) {
        stack<int> monoStack; //单调栈，栈内数据单调递减
        vector<int> result(T.size(), 0);

        for(int index = 0; index < T.size(); ++index) {
            while(monoStack.size() && T[monoStack.top()] < T[index]) {
                result[monoStack.top()] = index - monoStack.top();
                monoStack.pop();
            }
            
            monoStack.push(index);
        }

        return result;
    }
};