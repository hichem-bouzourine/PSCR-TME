#include "strutil.h"
#include <iostream>

using namespace pr;
using namespace std;

int main()
{
    const char *str = "Hello world";
    char *strCopy = newcopy(str);

    cout << str << '-' << length(str) << endl;
    cout << strCopy << '-' << length(strCopy) << endl;

    delete[] strCopy;
}