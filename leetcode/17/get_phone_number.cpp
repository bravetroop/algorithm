#include <vector>
#include <string>
#include <iostream>

using namespace std;

class Solution {
public:
    bool getString(char ch, char& begin, int& length) {
        if (ch < '7') {
            begin = ((ch - '2')*3) + 'a';
            length = 3;
        } else if (ch == '7') {
            begin = 'p';
            length = 4;
        } else if (ch == '8') {
            begin = 't';
            length = 3;
        } else if (ch == '9') {
            begin = 'w';
            length = 4;
        }

        return true;
    }

    void getToken(const char* digits, int len, string& str, vector<string>& result) {
        int index = 0;
        char begin = 0;
        int length = 0;

        if (len == 0) {
            result.push_back(str);
            return;
        }

        getString(*digits, begin, length);

        string strBak = str;
        for (index = 0; index < length; ++index) {
            str = strBak;
            str += (begin + index);
            getToken(digits+1, len - 1, str, result);
        }
    }

    vector<string> letterCombinations(string digits) {
        string str = "";
        vector<string> result;

        if (digits.length() > 0) {
            getToken(digits.c_str(), digits.length(), str, result);
        }


        for (int index = 0; index < result.size(); ++index) {
            cout << result[index] << " ";
        }
        cout << endl;

        return result;
    }
};

int main()
{
    Solution sol;
    sol.letterCombinations("27");
}