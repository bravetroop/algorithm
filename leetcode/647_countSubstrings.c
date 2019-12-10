class Solution {
public:
    int countSubstrings(string s) {
        int index = 0;
        int total = 0;
        int len = s.length();
        
        if (len == 0) {
            return 0;
        }

        for(index = 0; index < len; ++index) {
            total += expand(s, index, index);
            total += expand(s, index-1, index);
            //total += expand(s, index, index+1);
        }

        return total;
    };

    int expand(string s, int start, int end) {
        int len = s.length();
        int total = 0;

        while( (start >= 0)  && (end < len)) {
            if( s[start] == s[end]) {
                --start;
                ++end;
                ++total;
            } else {
                break;
            }
        }

        return total;
    };

};
