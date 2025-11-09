#include "LibTables.h"
#include <iostream> 

//w tym pliku sa funkcje od tablic

long double* tworzenie_tablicy1D(int rozmiar) //tworzy tablice o danym rozmiarze
{
    long double* tablica = nullptr; //tworzy wskaznik

    try
    {
        tablica = new long double[rozmiar]; //tworzy pusta tablice o podanym rozmiarze(lub nie jesli niepoprawne dane)
    }
    catch (std::bad_alloc)
    {
        std::cerr << "!"; //wypisuje blad gdy nie mozna stworzyc tablicy
        exit(0); //konczy dzialanie programu
    }
    return tablica; //zwraca wskaznik do tablicy
}


long double**tworzenie_tablicy2D(int wiersze, int kolumny)
{
    long double** tablica = nullptr; //tworzy wskaznik

    try
    {
        tablica = new long double* [wiersze]; //tworzy pusta tablice o podanym rozmiarze(lub nie jesli niepoprawne dane)
    }
    catch (std::bad_alloc)
    {
        std::cerr << "!!"; //wypisuje blad gdy nie mozna stworzyc tablicy
        exit(0); //konczy dzialanie programu
    }
    for (int i = 0; i < wiersze; i++)
    {
        tablica[i] = tworzenie_tablicy1D(kolumny);
    }
    return tablica; //zwraca wskaznik do tablicy
}
