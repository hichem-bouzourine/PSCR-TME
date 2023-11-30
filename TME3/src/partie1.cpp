#include "partie1.h"
#include <iostream>
#include <vector>
#include <string>
#include <cassert>
using namespace std;

int main()
{
    vector<string> vector;
    vector.push_back("Hichem");
    vector.push_back("Hichem");
    vector.push_back("Hichem");
    vector.push_back("Hichem");
    vector.push_back("BOUZOURINE");
    vector.push_back("BOUZOURINE");

    if (vector.size() == pr::count(vector.begin(), vector.end()))
        cout << "Bon" << endl;
    else
        cout << "ça marche pas" << endl;

    cout << pr::count_if_equal(vector.begin(), vector.end(), "Hichem") << endl;
    cout << pr::count_if_equal(vector.begin(), vector.end(), "BOUZOURINE") << endl;

    return 0;
}
