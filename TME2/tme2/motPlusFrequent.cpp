#include <iostream>
#include <fstream>
#include <regex>
#include <chrono>
#include <vector>
#include <string>

#include "HashMap.hpp"

using namespace std;

int main()
{
    using namespace std;
    using namespace std::chrono;

    ifstream input = ifstream("WarAndPeace.txt");

    auto start = steady_clock::now();
    cout << "Parsing War and Peace" << endl;

    HashTable<string, int> myHashTable(10000);

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

        int *count = myHashTable.get(word);
        if (count)
        {
            myHashTable.put(word, *count + 1);
            // *(count) ++;
        }
        else
        {
            myHashTable.put(word, 1);
        }
    }
    input.close();

    cout << "Finished Parsing War and Peace" << endl;

    auto end = steady_clock::now();
    cout << "Parsing took "
         << duration_cast<milliseconds>(end - start).count()
         << "ms.\n";

    cout << "Found a total of " << nombre_lu << " words." << endl;
    cout << "Nombre de mots differents est:" << myHashTable.size() << endl;

    cout << "Nombre d'occurences du mot war: " << *myHashTable.get("war") << endl;
    cout << "Nombre d'occurences du mot peace: " << *myHashTable.get("peace") << endl;

    return 0;
}
