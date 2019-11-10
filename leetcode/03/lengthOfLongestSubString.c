/*
 * lengthOfLongestSubString.c
 *
 *  Created on: Nov 10, 2019
 *      Author: shijie
 */

typedef struct
{
    int exist;
    int index;
}Occur;

int lengthOfLongestSubstring(char * s) {
    int len = 0;
    int index = 0;
    int maxLen = 0;
    int retLen = 0;
    Occur arr[256] = {0};

    int subStrBegin = 0;
    int subStrIndex = 0;

    if(0 == s)
    {
        return 0;
    }

    len = strlen(s);

    for(index = 0; index < len; ++index)
    {
        char ch = s[index];

        //如果该字符已经存在
        if(arr[ch].exist)
        {
        	//判断最大长度
            if(maxLen > retLen)
            {
                retLen = maxLen;
            }

            //清除子串中该字符之前的字符
            for(subStrIndex = subStrBegin; subStrIndex < index; ++subStrIndex)
            {
                if(ch != s[subStrIndex])
                {
                    arr[s[subStrIndex]].exist = 0;
                }
                else
                {
                    break;
                }
            }

            //重新记录子串的开始位置
            subStrBegin = (arr[ch].index+1);
            maxLen = index - arr[ch].index;
        }
        else
        {
            ++maxLen;
        }

        //标记该字符在子串中出现，并记录索引
        arr[ch].exist = 1;
        arr[ch].index = index;
    }

    if(maxLen > retLen)
    {
        retLen = maxLen;
    }

    return retLen;
}


