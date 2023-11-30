#ifndef Q1Q2_H_
#define Q1Q2_H_

#include <string>
namespace pr
{
    template <typename iterator>
    size_t count(iterator begin, iterator end)
    {
        size_t sz = 0;
        while (begin != end)
        {
            ++begin;
            ++sz;
        }
        return sz;
    }
    template <typename iterator, typename T>
    size_t count_if_equal(iterator begin, iterator end, const T &target)
    {
        size_t sz = 0;
        while (begin != end)
        {
            if (*begin == target)
            {
                ++sz;
            }
            ++begin;
        }
        return sz;
    }

}

#endif