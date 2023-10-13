#include <iostream>
#include "Banque.h"
#include "Compte.h"
#include "transferts.h"

using namespace std;

const int NB_THREAD = 10;

int main()
{
	using namespace pr;
	vector<thread> threads;
	threads.reserve(NB_THREAD);
	Banque b(80, 500); // banque de 80 comptes avec 500 Euros chaque un.

	// TODO : creer des threads qui font ce qui est demandé
	for (int i = 0; i < NB_THREAD; i++)
	{
		threads.emplace_back(transfertJob, i, ref(b));

		auto time = rand() % 20;
		// this_thread::sleep_for(std::chrono::milliseconds(time));
		cout << "thread created ... " << endl;
	}

	for (auto &t : threads)
	{
		t.join();
	}

	// TODO : tester solde = NB_THREAD * JP
	return 0;
}
