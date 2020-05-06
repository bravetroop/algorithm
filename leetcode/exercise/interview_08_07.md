无重复字符串的排列组合。编写一种方法，计算某字符串的所有排列组合，字符串每个字符均不相同。

 示例1:

 输入：S = "qwe"
 输出：["qwe", "qew", "wqe", "weq", "ewq", "eqw"]


 示例2:

 输入：S = "ab"
 输出：["ab", "ba"]


 提示:


字符都是英文字母。
字符串长度在[1, 9]之间。

~~~cpp
class Solution {
public:
    vector<string> permutation(string S) {
        queue<string> que;
        vector<string> result;
        int len = S.size();
        if (S.size() == 0) {
            return result;
        }

        string firstStr;
        firstStr.insert(firstStr.begin(), S[0]);

        que.push(firstStr);
        for (int index = 1; index < len; ++index) {
            int queLen = que.size();
            for (int i = 0; i < queLen; ++i) {
                string& str = que.front();
                for (int j = 0; j <= str.length(); ++j) {
                    string tmp = str;
                    tmp.insert(tmp.begin() + j, S[index]);
                    que.push(tmp);
                }
                que.pop();
            }
        }

        while (!que.empty()) {
            result.push_back(que.front());
            que.pop();
        }

        return result;
    }
};
~~~