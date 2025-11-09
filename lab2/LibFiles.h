#ifndef LIBFILES_H
#define LIBFILES_H
#include <string>
#include <fstream>
/*
* sprawdza czy plik ma dobra nazwe(jak nie to konczy program)
* @param nazwa pliku ktory sprawdzamy
*/
void test_nazwy(std::string nazwa);

/*
* zczytuje dane z pliku .txt do tablicy
* @param dwuwymiarowa tablica dynamiczna przechowujaca dane
* @param ilosc wierszy tablicy
*/
void zczytywanie_wspolrzednych(long double** tablica, int wiersze);

/*
* liczy bledy pomiarowe, wypisuje je do pliku i wyznacza najmniejszy blad pomiarowy
* @param tablica z danymi nieznanego modelu
* @param tablica z siatkami pozostalych modeli
*/
void wyznacz_przybliz(long double** nieznany, long double** siatka);

/*
* wypisuje dane konkretnego przyblizenia z siatki do pliku
* @param tablica z siatkami modeli
* @param referencja do pliku wyjsciowego
* @param numer pozycji na ktorej jest najdokladniejsze przyblizenie
*/
void wypisywanie_tabeli(long double** siatka, std::ofstream& wy, int j);

/*
* liczy blad pomiarowyw wedlug danego wzoru
* @param tablica z danymi nieznanego modelu
* @param tablica z siatkami modeli
* @param numer pozycji na ktorej jest model ktorego blad pomiarowy liczymy
* @result blad pomiarowy dla danego modelu
*/
long double liczenie_bledu(long double** nieznany, long double** siatka, int j);

#endif 
