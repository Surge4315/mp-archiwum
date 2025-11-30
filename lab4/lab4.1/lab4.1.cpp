#include <iostream>
#include <stack>
#include <fstream>
#include <string>
#include "LibFiles.h"
#include "LibTables.h"
#include "LibZ41.h"
using namespace std;


int main()
{
    string nazwa;
    cout << "podaj nazwe pliku wejsciowego" << endl;
    cin >> nazwa;
    F_test_nazwy(nazwa); //testuje nazwe pliku czy jest ok
    ifstream we;
    we.open(nazwa);
    if (!we)
    {
        cerr << "nie mozna utworzyc pliku!";
        cin.ignore();
        exit(0);
    }
    int rozmiar;
    we >> rozmiar; //zczytuje rozmiar tablicy
    int* tablica = nullptr;
    tablica = T_tworzenie_tablicy1D(rozmiar);
    F_zczytywanie_danych(tablica, we, rozmiar); //zczytujemy dane do tablicy dynamicznej
    we.close();

    stack <int> stosik; //adapter stosu
    lista* head = nullptr; //glowa listy jednokierunkowej
    int lj_rozm = 0;//rozmiar listy jednokierunkowej
    for (int i = 0; i < rozmiar; i++)
    {

        Z_dodaj_element(head, lj_rozm, tablica[i]);//dodajemy elementy tablicy do listy
        stosik.push(tablica[i]); //dodajemy element do stosu

    }
    cout << "dla listy jednokierunkowej" << endl;
    Z_wypisz_info(head, lj_rozm);
    Z_dodaj_element(head, lj_rozm, 72);
    Z_wypisz_info(head, lj_rozm);
    Z_usun_element_listy(head, lj_rozm);
    Z_wypisz_info(head, lj_rozm);

    cout << endl << endl << "dla tablicy dynamicznej" << endl;
    T_wypisywanie_tablicy(tablica, rozmiar);
    T_dodaj_element(tablica, rozmiar, 7456);
    T_wypisywanie_tablicy(tablica, rozmiar);
    T_usun_element(tablica, rozmiar);
    T_wypisywanie_tablicy(tablica, rozmiar);
    cout<<tablica[rozmiar-1]<<endl; //ostatni element
    cout<<rozmiar<<endl; //ilosc elementow
    if (tablica == nullptr)//jesli stos pusty
    {
        cout << "pusty" << endl;
    }
    else 
    {
        cout << "niepusty" << endl;
    }

    cout << endl << endl << "dla adaptera stosu" << endl;
    cout << stosik.top() << endl; //wypisuje element ze szczytu
    cout << stosik.size() << endl; //wypisuje rozmiar stosu
    stosik.pop(); //zdjecie elementu na szczycie
    cout << stosik.size() << endl; 
    cout << stosik.empty() << endl;//wypisanie czy pusty(jesli 1 to tak jesli 0 to nie)
}
