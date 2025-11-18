#include <iostream>
#include <fstream>
#include <cmath>
#include "LibFiles.h"
#include "LibTables.h"
#include "Lib_Z3.h"
using namespace std;

int main()
{
    string nazwa;
    cout << "podaj nazwe pliku wejsciowego" << endl;
    cin >> nazwa;
    F_test_nazwy(nazwa); //testuje nazwe pliku czy jest ok
    ifstream we;
    we.open(nazwa);
    if (!we)
    {
        cerr << "nie mozna utworzyc pliku!";
        cin.ignore();
        exit(0);
    }

    string nazwa_wy;
    cout << "podaj nazwe pliku wyjsciowego" << endl;
    cin >> nazwa_wy;
    F_test_nazwy(nazwa_wy); //testuje nazwe pliku czy jest ok
    ofstream wy;
    wy.open(nazwa_wy);
    if (!wy)
    {
        cerr << "nie mozna utworzyc pliku!";
        cin.ignore();
        exit(0);
    }

    int ilosc; //ilosc serii danych
    we >> ilosc;
    Z_zakres215(ilosc);
    for (int ile = 0; ile < ilosc; ile++)
    {
        int rozmiar_d;
        we >> rozmiar_d; //rozmiar tabeli z danymi
        Z_zakres215(rozmiar_d);
        int* dane = nullptr;
        dane = T_tworzenie_tablicy1D(rozmiar_d); //tworzy tablice zawierajaca dane
        F_zczytywanie_wspolrzednych(dane, we, rozmiar_d);

        int rozmiar_s;
        we >> rozmiar_s; //rozmiar tabeli z szukanymi
        Z_zakres215(rozmiar_s);
        int* szukane = nullptr;
        szukane = T_tworzenie_tablicy1D(rozmiar_s); //tworzy tabele zwierajaca szukane
        F_zczytywanie_wspolrzednych(szukane, we, rozmiar_s);

        

        for (int nr_szuk = 0; nr_szuk < rozmiar_s; nr_szuk++) //przechodzi przez wszystkie szukane
        {
            int i = Z_ile_wystapien(dane, rozmiar_d, szukane[nr_szuk]);
            int j;
            if (i == 0) //jesli elementu nie ma to j = -1
            {
                j = -1;
            }
            else if (i == rozmiar_d) //jesli wszystkie elementy sa szukana to j = 0
            {
                j = 0;
            }
            else
            {
                j = Z_interpolacja(dane, rozmiar_d, szukane[nr_szuk]);
            }
            wy << "(" << i << " " << j << ")";
        }
        wy << endl;
        Z_bezpowt(dane, rozmiar_d, wy);
        wy << endl << endl; //by oddzielic 

        delete[] dane; //przygotowujemy tablice dynamiczne na nowa serie danych
        delete[] szukane;
        
    }
    we.close();
    wy.close();

}

