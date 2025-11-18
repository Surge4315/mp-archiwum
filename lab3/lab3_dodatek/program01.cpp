// podajesz rozmiar tablicy, nazwe pliku wynikowego i tyle (ma byc zrobiony jak sie uczymy)
// nie lubie pascala (idzie od 1 a nie od 0 i wszystko szlag trafia)

#include <iostream>
#include "LibTables.h"
#include "LibFiles.h"
using namespace std;

int main()
{
    int n;
    cout << "podaj liczbe"<<endl;
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

    int* b = nullptr;
    b = T_tworzenie_tablicy1D(n);
    int i = 0; //liczba dotychczas wygenerowanych podzbiorów
    int p, j;
    do
    {
        F_wypisywanie_tablicy(b, wy, n);
        i = i + 1;
        p = 0; //nie od 1 bo pascal liczy od 1 nie od 0 a liczymy od pierwszego elementu
        j = i; //j staje sie numerem obecnie generowanego podciagu
        while (j % 2 == 0) //dopoki j jest parzyste dziel je calkowicie przez 2 i zwiekszaj p o 1
        {
            j = j / 2;
            p = p + 1;
        }
        cout << endl;
        //mozna wywalic if bo while(p<n) robi teraz to samo
        b[p] = 1 - b[p]; //odejmujemy/dodajemy element zbioru o numerze p 
        
    } while (p < n);  //jesli p jest wieksze od n to przeszlismy przez wszystkie podzbiory
    wy.close();
}
