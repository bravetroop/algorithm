class Solution {
public:
    bool isValidV4(string& IP) {
        int num = 0;
        int split = 0;

        if (IP.length() > 15) {
            return false;
        }

        for (int index = 0; index < IP.length(); ++index) {
            char ch = IP[index];
            //(192.168.0.1/192.168.1.0/192.168.1.01)
            //点分十进制第一位是0,并且不是最后一个数字，当前数字后面一位也不是'.',则返回false
            if ((num == 0 && ch == '0')
                    && (index < IP.length()-1 
                    && IP[index+1] != '.')) {
                return false;
            } else if (isdigit(ch)) {
                num = (num * 10) + (ch - '0');
                //数字超过255
                if (num > 0xFF) {
                    return false;
                }
            } else if (ch == '.' 
                        && index < IP.length()-1
                        && IP[index+1] != '.') {
                num = 0;
                ++split;
            } else {
                return false;
            }
        }

        return split == 3 ? true : false;
    }

    bool isValidV6(string& IP) {
        int split = 0;
        int chLen = 0;

        if (IP.length() > 39) {
            return false;
        }

        for (int index = 0; index < IP.length(); ++index) {
            char ch = IP[index];
            
            if (isdigit(ch) 
                    || (ch >= 'a' && ch <= 'f')
                    || (ch >= 'A' && ch <= 'F')) {
                //分割数的长度
                if (chLen > 3) {
                    return false;
                }
                ++chLen;
            } else if (ch == ':' 
                        && index != IP.length()-1
                        && IP[index+1] != ':') { //是':',并且下一个数字不是':'
                ++split;
                chLen = 0;
            } else {
                return false;
            }
        }

        return split == 7 ? true : false;;
    }

    string validIPAddress(string IP) {
        if(isValidV4(IP)) {
            return "IPv4";
        }

        if (isValidV6(IP)) {
            return "IPv6";
        }

        return "Neither";
    }
};