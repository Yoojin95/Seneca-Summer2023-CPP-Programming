#include "cstring.h"

namespace sdds {

    int strLen(const char* s)
    {
        int length = 0;
        
        while (s[length])
            length++;

        return length;
    }

    void strCpy(char* des, const char* src)
    {
        int i = 0;

        while (src[i]) {
            des[i] = src[i];
            i++;
        }

        des[i] = '\0';
    }

    int strCmp(const char* s1, const char* s2)
    {
        int i = 0, result = 0;
        bool flag = false;

        while (!flag) {
            if (s1[i] != s2[i] || s1[i] == '\0' || s2[i] == '\0') {
                result = s1[i] - s2[i];
                flag = true;
            }

            i++;
        }

        return result;
    }

}