#ifndef LIB_Z3_H
#define LIB_Z3_H
#include <iostream>
//funkcje do zadania 3


/*
* funkcja sprawdza czy liczba jest pomiedzy 1 a 2^15
* @param liczba ktora sprawdzamy
*/
void Z_zakres215(int n);

/*
* funkcja sprawdza czy liczba jest pomiedzy 2^-48 a 2^48
* @param liczba ktora sprawdzamy
*/
void Z_zakres248(int n);

/*
* szuka ilosci wystapien liczby o danym indeksie w tablicy (podfunkcja funkcji Z_ile_wystapien)
* @param tablica - wskaznik do tablicy dynamicznej
* @param rozmiar - rozmiar tablicy
* @param indeks - indeks elementu ktorego ilosci szukamy
* @return ilosc wystapien
*/
int ilosc(int* tablica, int rozmiar, int indeks);

/*
* funkcja szuka binarnie ilosci wystapien liczby w tablicy
* @param dane - tablica ktora sprawdzamy
* @param rozmiar - rozmiar przeszukiwanej tablicy
* @param szukana - szukana liczba
* @return ilosc wystapien
*/
int Z_ile_wystapien(int* tablica, int rozmiar, int szukana);


/*
* funkcja szuka interpolacyjnie liczby w tablicy
* @param dane - tablica ktora sprawdzamy
* @param rozmiar - rozmiar przeszukiwanej tablicy
* @param szukana - szukana liczba
* @return indeks gdzie znalaziono liczbe
*/
int Z_interpolacja(int* tablica, int rozmiar, int szukana);
#endif

/*
* funkcja wypisuje elementy tablicy bez powtorzen
* @param dane - tablica ktora wypisujemy
* @param rozmiar - rozmiar przeszukiwanej tablicy
* @param wy - referencja do pliku wyjsciowego
*/
void Z_bezpowt(int* tablica, int rozmiar, std::ofstream& wy);