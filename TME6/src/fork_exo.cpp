#include <iostream>
#include <unistd.h>
#include <sys/types.h>
#include <sys/wait.h>

int main()
{
	const int N = 3;
	std::cout << "main pid=" << getpid() << std::endl;

	int nombreFils = 0;

	for (int i = 1, j = N; i <= N && j == N; i++)
	{
		if (fork() == 0)
		{
			nombreFils = 0;
		}
		else
		{
			nombreFils++;
			break;
		}
		std::cout << " i:j " << i << ":" << j << std::endl;
		for (int k = 1; k <= i && j == N; k++)
		{
			if (fork() == 0)
			{
				nombreFils = 0;
				j = 0;
				std::cout << " k:j " << k << ":" << j << std::endl;
			}
			else
			{
				nombreFils++;
			}
		}
	}
	for (int ii = 0; ii < nombreFils; ii++)
	{
		if (wait(NULL) == -1)
			std::cout << "error trop" << std::endl;
	}
	if (wait(NULL) != -1) // je confirme que j'ai pas de fils
		std::cout << "error pas assez" << std::endl;

	std::cout << "la fin du processus " << getpid() << std::endl;
	return 0;
}
