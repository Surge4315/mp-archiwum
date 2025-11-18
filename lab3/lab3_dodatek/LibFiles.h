#ifndef LIBFILES_H
#define LIBFILES_H
#include <string>
#include <fstream>
/*
* sprawdza czy plik ma dobra nazwe(jak nie to konczy program)
* @param nazwa - nazwa pliku ktory sprawdzamy
*/
void F_test_nazwy(std::string nazwa);

/*
* zczytuje dane z pliku .txt do tablicy
* @param tablica - tablica dynamiczna przechowujaca dane
* @param we - referencja do pliku wejsciowego
* @param rozmiar - rozmiar tablicy
*/
void F_zczytywanie_wspolrzednych(int* tablica, std::ifstream& we, int rozmiar);

/*
* wypisuje dane tablicy do pliku
* @param tablica - tablica do wypisania
* @param wy - referencja do pliku wyjsciowego
* @param rozmiar - rozmiar tabeli
*/
void F_wypisywanie_tablicy(int* tabela, std::ofstream& wy, int rozmiar);


/*
* wypisuje do pliku elementy tablicy dana ilosc razy
* @param tablica - wskaznik do tablicy dynamicznej
* @param ile - wskaznik do tablicy z iloscia wystapien
* @param wy - referencja do pliku wyjsciowego
* @param zakres - zakres dla którego wypisujemy dane
*/
void F_wypisywanie_tablicy_razy(int* tablica, int* ile, std::ofstream& wy, int zakres);

#endif 
