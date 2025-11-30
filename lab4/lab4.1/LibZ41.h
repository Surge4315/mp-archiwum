#ifndef LIBZ41_H_
#define LIBZ41_H_
//funkcje do zadania 4.1

struct lista
{
    int liczba; //dana listy
    lista* next; //wskaznik do kolejnego elementu listy
};

/*
* funkcja usuwa element z listy jednokierunkowej
* @param head - referencja do wskaznika do glowy listy jednokierunkowej
* @param lj_rozm - referencja do rozmiaru tablicy
*/
void Z_usun_element_listy(lista*& head, int& lj_rozm);

/*
* funkcja wypisuje ilosc elementow listy i jej szczytowy element
* @param head - referencja do wskaznika do glowy listy jednokierunkowej
* @param lj_rozm - referencja do rozmiaru tablicy
*/
void Z_wypisz_info(lista*& head, int& lj_rozm);

/*
* funkcja dodaje element do listy jednokierunkowej
* @param head - referencja do wskaznika do glowy listy jednokierunkowej
* @param lj_rozm - referencja do rozmiaru tablicy
* @param liczba - liczba do dodania do listy
*/
void Z_dodaj_element(lista*& head, int& lj_rozm, int liczba);

#endif


