#include"LibZ41.h"
#include <fstream>
#include <iostream>
using namespace std;

void Z_usun_element_listy(lista*& head, int& lj_rozm)
{
    if (head == nullptr)//pusta tablica
    {
        return;
    }
    if (head->next == nullptr)//jesli lista ma jeden element
    {
        delete head;//usuwamy jedyny element
        lj_rozm--; //rozmiar mniejszy o 1
        return;
    }
    lista* temp = head;
    head = head->next; //glowa zostaje nastepnym elementem
    delete temp; //usuwamy byla glowe
    lj_rozm--; //rozmiar mniejszy o 1
    return;

}

void Z_wypisz_info(lista*& head, int& lj_rozm)
{
    if (lj_rozm == 0)
    {
        cout << "lista jest pusta"<<endl;
    }
    else
    {
        cout << "w liscie jest " << lj_rozm << " elementow" << endl;
        cout << "element szczytowy: " << head->liczba<<endl;
    }
}

void Z_dodaj_element(lista*& head, int& lj_rozm, int liczba)
{
    lista* new_e = nullptr; //wskaznik do kolejnego elementu
    new_e = new lista; //nowy wskaznik pokazuje na nowy element
    new_e->liczba = liczba; //zczytujemy dane do nowego elementu
    lj_rozm++;
    new_e->next = head; //wskaznik nowwego elementu wskazuje na obecna glowe
    head = new_e; //glowa listy zostaje nowy element
}
