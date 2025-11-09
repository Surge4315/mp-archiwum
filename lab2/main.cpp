#include <iostream>
#include <fstream>
#include <cmath>
#include <string>
#include "LibTables.h"
#include "LibFiles.h"
using namespace std;

int main()
{
    cout << "podaj najpierw nazwe pliku nieznanego modelu a potem pliku siatki" << endl;
    long double** nieznany = nullptr;
    nieznany = tworzenie_tablicy2D(2, 106); //tablica dla nieznanego wykresu
    zczytywanie_wspolrzednych(nieznany, 2);
    
    long double** siatka = nullptr;
    siatka = tworzenie_tablicy2D(162, 106); //tablica dla wszystkich 81 serii danych
    zczytywanie_wspolrzednych(siatka, 162);
    wyznacz_przybliz(nieznany, siatka);
}
