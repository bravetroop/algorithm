//
// Created by s00400380 on 2019/12/18.
//

#include <string>
using std::string;

class Solution {
public:
    bool repeatedSubstringPattern(string s) {
        int half_len = 0;
        int length = s.length();
        bool result = false;

        if (0 == length) {
            return false;
        }

        half_len = length / 2;
        for (int index = 1; index <= half_len; ++index) {
            if (length % index) {
                continue;
            }
            string subStr = s.substr(0, index);

            bool bMatch = true;
            for (int subIndex = index; subIndex < length; subIndex += index) {
                string subStr2 = s.substr(subIndex, index);
                if  (subStr != subStr2) {
                    bMatch = false;
                    break;
                }
            }

            if(bMatch) {
                result = true;
                break;
            }
        }

        return result;
    }
};
