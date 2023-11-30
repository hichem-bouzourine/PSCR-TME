#include "Banque.h"

#include <iostream>

using namespace std;

namespace pr
{

	void Banque::transfert(size_t deb, size_t cred, unsigned int val)
	{
		// unique_lock<recursive_mutex> g(m);			Réponse de la question 9
		Compte &debiteur = comptes[deb];
		Compte &crediteur = comptes[cred];

		/*Alternative : utiliser lock avec plusieurs mutex !*/
		if (deb < cred)
		{ // On prend arbitrairement un ordre sur les locks
			debiteur.getMutex().lock();
			crediteur.getMutex().lock();
		}
		else if (cred < deb)
		{
			crediteur.getMutex().lock();
			debiteur.getMutex().lock();
		}
		else
		{
			return; // On transfert vers le même compte, autant ne rien faire...
		}

		if (debiteur.debiter(val))
		{
			crediteur.crediter(val);
		}
		debiteur.getMutex().unlock();
		crediteur.getMutex().unlock();
	}
	size_t Banque::size() const
	{
		// unique_lock<recursive_mutex> g(m);		Réponse de la question 9

		return comptes.size();
	}
	bool Banque::comptabiliser(int attendu) const
	{
		// unique_lock<recursive_mutex> g(m);		Réponse de la question 9

		int bilan = 0;
		int id = 0;
		for (const auto &compte : comptes)
		{							  // Les comptes sont parcourus dans l'ordre.
			compte.getMutex().lock(); // On prend le verrou sur le compte.
			if (compte.getSolde() < 0)
			{
				cout << "Compte " << id << " en négatif : " << compte.getSolde() << endl;
			}
			bilan += compte.getSolde();
			id++;
		}
		if (bilan != attendu)
		{
			cout << "Bilan comptable faux : attendu " << attendu << " obtenu : " << bilan << endl;
		}

		for (const auto &compte : comptes)
		{
			compte.getMutex().unlock(); // On déverrouille tous les verrous
		}
		return bilan == attendu;
	}
}
