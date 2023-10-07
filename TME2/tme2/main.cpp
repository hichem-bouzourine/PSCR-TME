#include <iostream>
#include <fstream>
#include <regex>
#include <chrono>
#include <vector>
#include <string>

using namespace std;

int nombreOccurences(const vector<pair<string, int>> &vect, string mot)
{
	for (size_t it = 0; it < vect.size(); it++)
		if (vect[it].first == mot)
			return vect[it].second;
	return 0;
}

int main()
{
	using namespace std;
	using namespace std::chrono;

	ifstream input = ifstream("WarAndPeace.txt");

	auto start = steady_clock::now();
	cout << "Parsing War and Peace" << endl;

	vector<pair<string, int>> vect;

	size_t nombre_lu = 0;
	// prochain mot lu
	string word;
	// une regex qui reconnait les caractères anormaux (négation des lettres)
	regex re(R"([^a-zA-Z])");
	while (input >> word)
	{
		// élimine la ponctuation et les caractères spéciaux
		word = regex_replace(word, re, "");
		// passe en lowercase
		transform(word.begin(), word.end(), word.begin(), ::tolower);

		// word est maintenant "tout propre"
		if (nombre_lu % 100 == 0)
		{
			// on affiche un mot "propre" sur 100
			cout << nombre_lu << ": " << word << endl;
		}
		nombre_lu++;

		bool trouve = false;

		for (size_t it = 0; it < vect.size(); it++)
		{
			if (vect[it].first == word)
			{
				vect[it].second = vect[it].second + 1;
				trouve = true;
				break;
			}
		}
		if (!trouve)
			vect.push_back(make_pair(word, 1));
	}
	input.close();

	cout << "Finished Parsing War and Peace" << endl;

	auto end = steady_clock::now();
	cout << "Parsing took "
		 << duration_cast<milliseconds>(end - start).count()
		 << "ms.\n";

	cout << "Found a total of " << nombre_lu << " words." << endl;
	cout << "Nombre de mots differents est:" << vect.size() << endl;

	cout << "Nombre d'occurences du mot war: " << nombreOccurences(vect, "war") << endl;
	cout << "Nombre d'occurences du mot peace: " << nombreOccurences(vect, "peace") << endl;
	cout << "Nombre d'occurences du mot toto: " << nombreOccurences(vect, "toto") << endl;
	return 0;
}
