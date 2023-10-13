#include <iostream>
#include "Banque.h"

using namespace std;
using namespace pr;

void transfertJob(int index, Banque &banque)
{
    cout << "Started: " << index << endl;

    for (int i = 0; i < 1000; i++)
    {
        int deb = rand() % banque.size();
        int cred = rand() % banque.size();

        int val = rand() % 100;

        banque.transfert(deb, cred, val);
    }

    cout << "Finished" << endl;
}
