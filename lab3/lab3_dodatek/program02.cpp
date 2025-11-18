#include <iostream>
#include "LibTables.h"
#include "LibFiles.h"
using namespace std;

int main()
{
    int n, k;
    cout << "podaj ilosc elementow zbioru" << endl;
    cin >> n;
    cout << "podaj ilosc elementow podzbioru" << endl;
    cin >> k;
    if (k >= n)
    {
        cerr << "zbyt duze k!";
        exit(0);
    }
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
    int* podzbior = nullptr;
    podzbior = T_tworzenie_tablicy1D(k); //tworzy tablice podzbioru

    //pseudokod na c++
    for (int i = 0; i < k; i++) //zaczyna od wypelnienia podzbioru elementami od pierwszego do 'k'
    {
        podzbior[i] = i + 1;
    }
    int p = k-1;
    while (p >= 0)
    {
        F_wypisywanie_tablicy(podzbior, wy, k); //wypisuje tablice do pliku
        if (podzbior[k - 1] == n) //jesli ostatni element ciagu jest elementem ostatnim
        {
            p = p - 1; //p zostaje pozycja ostatniego elementu w zbiorze
        }
        else
        {
            p = k-1; //p zostaje ostatnia pozycja ostatniego elementu w podzbiorze
        }
        if (p >= 0) //poki p jest wieksze lub rowne indeksowi pierwszego elementu
        {
            for (int i = k - 1; i >= p; i--)
            {
                podzbior[i] = podzbior[p] + i - p + 1; //zmien element o indeksie 'i' wedlug wzoru
            }
        }
    }
    wy.close();
}
