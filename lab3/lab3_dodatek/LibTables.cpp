#include "LibTables.h"
#include <iostream> 

//w tym pliku sa funkcje od tablic

int* T_tworzenie_tablicy1D(int rozmiar) //tworzy tablice o danym rozmiarze
{
    int* tablica = nullptr; //tworzy wskaznik

    try
    {
        tablica = new int[rozmiar] {}; //tworzy pusta tablice o podanym rozmiarze(lub nie jesli niepoprawne dane) z wartosciami 0
    }
    catch (std::bad_alloc)
    {
        std::cerr << "!"; //wypisuje blad gdy nie mozna stworzyc tablicy
        exit(0); //konczy dzialanie programu
    }
    return tablica; //zwraca wskaznik do tablicy
}


int**T_tworzenie_tablicy2D(int wiersze, int kolumny)
{
    int** tablica = nullptr; //tworzy wskaznik

    try
    {
        tablica = new int* [wiersze]; //tworzy pusta tablice o podanym rozmiarze(lub nie jesli niepoprawne dane)
    }
    catch (std::bad_alloc)
    {
        std::cerr << "!!"; //wypisuje blad gdy nie mozna stworzyc tablicy
        exit(0); //konczy dzialanie programu
    }
    for (int i = 0; i < wiersze; i++)
    {
        tablica[i] = T_tworzenie_tablicy1D(kolumny);
    }
    return tablica; //zwraca wskaznik do tablicy
}

void T_wypelnianie_tablicy_rosnaco(int* tablica, int rozmiar)
{
    for (int i = 0; i < rozmiar; i++)
    {
        tablica[i] = i + 1; //ustawia wartosci tablicy na 1, 2, 3, 4...
    }
}

void T_wypisywanie_tablicy(int* tablica, int rozmiar)
{
    for (int i = 0; i < rozmiar; i++)
    {
        std::cout << tablica[i] << " ";
    }
    std::cout << std::endl;
}

void T_wypisywanie_tablicy_razy(int* tablica, int* ile, int zakres)
{
    for (int i = 0; i <= zakres; i++)
    {
        for (int j = 0; j < ile[i]; j++) //wypisuje dane z tablica[i] ile[i] razy
        {
            std::cout << tablica[i] << " ";
        }
    }
    std::cout << std::endl;
}
