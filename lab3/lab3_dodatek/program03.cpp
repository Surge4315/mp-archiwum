#include <iostream>
#include "LibTables.h"
#include "LibFiles.h"
using namespace std;

int main()
{
    int n;
    cout << "podaj liczbe " << endl;
    cin >> n;
    string nazwa;
    cout << "podaj nazwe pliku wyjsciowego" << endl;
    cin >> nazwa;
    F_test_nazwy(nazwa); //testuje nazwe pliku czy jest ok
    ofstream wy;
    wy.open(nazwa);
    if (!wy)
    {
        cerr << "nie mozna utworzyc pliku!";
        cin.ignore();
        exit(0);
    }
    int* S = nullptr;
    S = T_tworzenie_tablicy1D(n);
    int* R = nullptr;  //tabela R wyznacza ilosc razy ile trzeba wypisac wartosc z tablicy S
    R = T_tworzenie_tablicy1D(n);

    //tutaj zaczyna się pseudokod zmieniony w c++
    int d = 0; //zaczynamy od indeksu 0
    S[0] = n;
    R[0] = 1;
    int el;
    F_wypisywanie_tablicy_razy(S, R, wy, n);
    while (S[0] > 1) //szukamy nastepnego podzialu
    {
        int sum = 0; //suma usunietych skladnikow
        if (S[d] == 1) //usun skladniki rowne jednosci
        {
            sum = sum + R[d]; //zwieksza sume o ilosc wypisan z pozycji d
            d = d - 1; //ustawia d na wczesniejsza pozycje
        }
        sum = sum + S[d]; //zwieksza sume o 
        R[d] = R[d] - 1; //zmniejszamy ilosc wypisan o 1
        el = S[d] - 1; //w pliku jest 'l' czyli el
        if (R[d] > 0) //jesli ilosc wypisan jest wieksza od 0, zwiekszamy zakres o 1
        {
            d = d + 1;
        }
        S[d] = el;
        R[d] = sum / el;
        el = sum % el;
        if (el != 0) //dodaj ostatni skladnik rowny 1
        {
            d = d + 1;
            S[d] = el;
            R[d] = 1;
        }
        F_wypisywanie_tablicy_razy(S, R, wy, d);
    }
    wy.close();
}
