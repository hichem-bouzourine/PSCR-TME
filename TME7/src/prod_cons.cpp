#include "Stack.h"
#include <iostream>
#include <unistd.h>
#include <sys/wait.h>
#include <vector>
#include <sys/mman.h>

using namespace std;
using namespace pr;

void producteur(Stack<char> *stack)
{
	cout << "Je suis un producteur";
	char c;
	while (cin.get(c))
	{
		stack->push(c);
	}
}

void consomateur(Stack<char> *stack)
{
	while (true)
	{
		char c = stack->pop();
		cout << c << flush;
	}
}

int main()
{

	/* TODO
	*À mettre dans un segment de mémoire partagé (anonyme)
	qui prend l'adresse
	* Construire la stak dans la mémoire partagée
	* syntaxe  :
		new (adresse choisie plutôt qu'un malloc) Constructeur (args)
	*/

	size_t len = sizeof(Stack<char>);

	void *addr = mmap(nullptr, len, PROT_READ | PROT_WRITE, MAP_SHARED | MAP_ANONYMOUS, -1, 0);

	Stack<char> *s = new (addr) Stack<char>();

	pid_t pp = fork();
	if (pp == 0)
	{
		producteur(s);
		return 0;
	}

	pid_t pc = fork();
	if (pc == 0)
	{
		consomateur(s);
		return 0;
	}

	wait(0);
	wait(0);

	munmap(addr, len);
	return 0;
}
