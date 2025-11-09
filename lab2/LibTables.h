#ifndef LIBTABLES_H
#define LIBTABLES_H

//tzw. doxygen comments
/*
* Funkcja tworzy tablice jednowymiarowa dynamiczna
* @param rozmiar - rozmiar tablicy
* @return adres utworzonej tablicy
*/
long double* tworzenie_tablicy1D(int rozmiar);

/*
* Funkcja tworzy tablice dwuwymiarowa dynamiczna
* @param wiersze - ilosc wierszy(dlugosc kolumny)
* @param kolumny - ilosc kolumn(dlugosc wiersza)
* @return adres utworzonej tablicy
*/
long double**tworzenie_tablicy2D(int wiersze, int kolumny);

#endif
