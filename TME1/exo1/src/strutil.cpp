#include "strutil.h"
#include <iostream>

namespace pr
{
    size_t length(const char *str)
    {
        size_t ret = 0;
        for (int i = 0; str[i]; ++i)
        {
            ++ret;
        }
        return ret;
    }

    char *newcopy(const char *src)
    {
        size_t n = length(src);
        char *dest = new char[n + 1];
        // avec <= pour attraper le dernier ’\0’
        for (size_t i = 0; i <= n; ++i)
        {
            dest[i] = src[i];
        }
        return dest;
    }
}