字符串压缩。利用字符重复出现的次数，编写一种方法，实现基本的字符串压缩功能。比如，字符串aabcccccaaa会变为a2b1c5a3。若“压缩”后的字符串没有变短，则返回原先的字符串。你可以假设字符串中只包含大小写英文字母（a至z）。

 示例1:

 输入："aabcccccaaa"
 输出："a2b1c5a3"

 示例2:

 输入："abbccd"
 输出："abbccd"
 解释："abbccd"压缩后为"a1b2c2d1"，比原字符串长度更长。

提示：
字符串长度在[0, 50000]范围内。

~~~cpp
class Solution {
public:
    string compressString(string S) {
        int num = 1;
        int length = S.length();
        if (length <= 1) {
            return S;
        }

        char ch = S[0];
        string str = "";
        str += ch;

        char nums[10] = {0};
        for(int index = 1; index < length; ++index) {
            if (S[index] != ch) {
                sprintf(nums, "%d", num);
                str += nums;
                ch = S[index];
                str += ch;
                num = 1;
            } else {
                ++num;
            }
        }
        sprintf(nums, "%d", num);
        str += nums;

        if(str.length() < length) {
            return str;
        }

        return S;
    }
};
~~~