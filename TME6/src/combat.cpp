#include <iostream>
#include <unistd.h>
#include <sys/wait.h>

#include "rsleep.h"

int pdv = 3;

/*Handler du signal*/
void perdrePdv(int)
{ // Respecter la signature des handler
    pdv--;
    std::cout << getpid() << " perd un pdv" << std::endl;

    if (pdv == 0)
    { // mort du processus
        std::cout << "Je meurs !" << std::endl;
    }
}

void attaque(pid_t adversaire)
{
    struct sigaction sa = {0};
    sa.sa_handler = &perdrePdv;
    sigaction(SIGINT, &sa, NULL); // Redef du handler pour le signal SIGINT
    if (kill(adversaire, SIGINT) == -1)
    {
        exit(0);
    }
    randsleep();
}

void defense()
{
    /*Désarmer le signal en posant son sigation à SIGIN*/
    struct sigaction sa = {0};
    sa.sa_handler = SIG_IGN; // routine qui fait ignorer le signal
    sigaction(SIGINT, &sa, NULL);
}

void combat(pid_t adversaire)
{
    while (1)
    {
        defense();
        attaque(adversaire);
    }
}

/*Voir comment faire les appels avec une situation père fils*/
int main()
{
    pid_t Eteocle = fork();
    if (Eteocle != 0)
    { // Code du père
        pid_t Polynice = fork();
    }
}