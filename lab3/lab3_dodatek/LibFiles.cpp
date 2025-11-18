#include "LibFiles.h"
#include <iostream>
#include <fstream>
#include <iomanip>
using namespace std;

//w tym pliku s¹ funkcje operuj¹ce na plikach

void F_test_nazwy(std::string nazwa_nieznany)
{
    size_t dl = nazwa_nieznany.length();

    if (dl > 4) //.txt to 4 znaki wiec musi byc przynajmniej 5 by plik mial nazwe 
    {   //sprawdza czy plik ma rozszerzenie .txt
        if (nazwa_nieznany[dl - 4] == '.' || nazwa_nieznany[dl - 3] == 't' || nazwa_nieznany[dl - 2] == 'x' || nazwa_nieznany[dl - 1] == 't')
        {
            return; //jak wszystko ok to konczy funkcje
        }
        else
        {
            cerr << "plik musi miec rozszerzenie .txt!";
            cin.ignore();
            exit(0);
        }

    }
    else
    {
        cerr << "bledna nazwa pliku!";
        cin.ignore();
        exit(0);
    }
}

void F_zczytywanie_wspolrzednych(int* tablica, ifstream& we, int rozmiar)
{
    for (int i = 0; i < rozmiar; i++)
    {
        we >> tablica[i];
    }
}
void F_wypisywanie_tablicy(int* tablica, ofstream& wy, int rozmiar)
{
    for (int i = 0; i < rozmiar; i++)
    {
        wy << tablica[i] << " "; //wypisuje dane y do pliku wynikowego
    }
    wy << endl;
}

void F_wypisywanie_tablicy_razy(int* tablica, int* ile, ofstream& wy, int zakres)
{
    for (int i = 0; i <= zakres; i++)
    {
        for (int j = 0; j < ile[i]; j++) //wypisuje dane z tablica[i] ile[i] razy do pliku
        {
            wy << tablica[i] << " ";
        }
    }
    wy << endl;
}




