#ifndef LIBTABLES_H
#define LIBTABLES_H

//tzw. doxygen comments
/*
* Funkcja tworzy tablice jednowymiarowa dynamiczna
* @param rozmiar - rozmiar tablicy
* @return adres utworzonej tablicy
*/
int* T_tworzenie_tablicy1D(int rozmiar);

/*
* Funkcja tworzy tablice dwuwymiarowa dynamiczna
* @param wiersze - ilosc wierszy(dlugosc kolumny)
* @param kolumny - ilosc kolumn(dlugosc wiersza)
* @return adres utworzonej tablicy
*/
int**T_tworzenie_tablicy2D(int wiersze, int kolumny);
/*
* wypelnia tablice elementami 1, 2, 3, 4....itp
* @param tablica - wskaznik do tablicy dynamicznej
* @param rozmiar - rozmiar tablicy dynamicznej
*/
void T_wypelnianie_tablicy_rosnaco(int* tablica, int rozmiar);
/*
* wypisuje elementy tablicy
* @param tablica - wskaznik do tablicy dynamicznej
* @param rozmiar - rozmiar tablicy dynamicznej
*/
void T_wypisywanie_tablicy(int* tablica, int rozmiar);

/*
* wypisuje elementy tablicy dana ilosc razy
* @param tablica - wskaznik do tablicy dynamicznej
* @param ile - wskaznik do tablicy z iloscia wystapien
* @param zakres - zakres dla którego wypisujemy dane 
*/
void T_wypisywanie_tablicy_razy(int* tablica, int* ile, int zakres);



#endif
