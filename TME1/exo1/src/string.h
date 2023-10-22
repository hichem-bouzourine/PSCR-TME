#include <iostream>

namespace pr
{
    class String
    {
    private:
        const char *str;

    public:
        String(char *str = "");
        String(const String &str);
        size_t length() const;
        int compare(const char *a, const char *b);

        ~String()
        {
            delete[] str;
        }

        String &operator=(const String &other);
        char operator[](size_t index) const;
        String operator++(String &s1, String &s2);
    };
}