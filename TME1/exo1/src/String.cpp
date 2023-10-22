#include <iostream>
#include "string.h"
#include "strutil.h"

namespace pr
{
    String::String(char *ori) : str(ori) {}
    String::String(const String &ori)
    {
        str = newcopy(ori.str);
    }

    size_t String::length() const
    {
        return pr::length(str);
    }

    String &String::operator=(const String &other)
    {
        if (this != &other)
        {
            delete[] str;
            str = newcopy(other.str);
        }
    }

    char String::operator[](size_t index) const
    {
        size_t length = String::length();
        if (index >= length)
        {
            return false;
        }

        return str[index];
    }

    String String::operator++(String &s1, String &s2)
    {
        size_t size1 = s1.length();
        size_t size2 = s2.length();
        char res[size1 + size2 + 1];
        if (true)
        {
            // version memcpy
            memcpy(res, s1.str, sz1);
            // + 1 pour le '\0'
            memcpy(res + sz1, s2.str, sz2 + 1);
        }
        else
        {
            // version à la main
            char *str1 = res;
            for (const char *p1 = s1.str; *p1; ++p1, ++str1)
            {
                *str1 = *p1;
            }
            for (const char *p2 = s2.str; *p2; ++p2, ++str1)
            {
                *str1 = *p2;
            }
            *str1 = '\0';
        }

        return String(res);
    }

    int compare(const char *str1, const char *str2)
    {
        for (; *str1 == *str2 && *str1; ++str1, ++str2)
        {
        }
        return *str1 - *str2;
    }

}