#include <iostream>
#include <fstream>
#include <string>
#include "LibFiles.h"
#include "ONPtoINF.h"
#include "INFtoONP.h"
using namespace std;

int main()
{
    ifstream we;
    ofstream wy;
    string plik;
    cout << "podaj nazwe pliku wejsciowego" << endl;
    cin >> plik; //zczytujemy nazwe pliku wejsciowego od uzytkownika
    F_test_nazwy(plik); //testujemy poprawnosc nazwy pliku
    we.open(plik);
    plik.clear(); //czyscimy zmienna
    cout << "podaj nazwe pliku wyjsciowego" << endl;
    cin >> plik;
    F_test_nazwy(plik);
    wy.open(plik);
    int ile; //ilosc serii danych
    we >> ile;
    string dzialanie; //
    for (int i = 0; i < ile+1; i++)
    {
        getline(we, dzialanie); //zczytujemy pierwsza linie dzialan
        //cout << dzialanie << " " << i << endl;
        if (dzialanie.size() < 6 || dzialanie.size() > 256) //jesli warunki rozmiaru pliku nie sa spelnione to przejdz do kolejnej linii
        {
            dzialanie.clear();//wyczysc obecny string
        }
        else
        {
            if (dzialanie[0] == 'O') //jesli pierwszy znak to O to mamy onp
            {
                ONP_zbedne(dzialanie); //usuwamy zbedne elementy
                wy <<"INF: "<< ONP_konwersja_do_INF(dzialanie) << endl; //wypisujemy konwersje
            }
            else //w drugim wypadku mamy inf
            {
                INF_zbedne(dzialanie);
                wy << "ONP: " << INF_konwersja_do_ONP(dzialanie) << endl;
            }
        }
    }
    we.close();
    wy.close();

}
