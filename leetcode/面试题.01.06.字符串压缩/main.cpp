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