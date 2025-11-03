#include <iostream>
#include <string>
#include <sstream>
#include <cmath>

using namespace std;



int** tworzenie_tablicy2D(int rozmiar) //tworzy tablice o danym rozmiarze
{
    int** tablica = nullptr; //tworzy wskaznik

    try
    {
        tablica = new int* [rozmiar]; //tworzy pusta tablice o podanym rozmiarze(lub nie jesli niepoprawne dane)
    }
    catch (std::bad_alloc)
    {
        std::cerr << "!!"; //wypisuje blad gdy nie mozna stworzyc tablicy
        exit(0); //konczy dzialanie programu
    }
    return tablica; //zwraca wskaznik do tablicy
}

int* tworzenie_tablicy1D(int rozmiar) //tworzy tablice o danym rozmiarze
{
    int* tablica = nullptr; //tworzy wskaznik

    try
    {
        tablica = new int[rozmiar]; //tworzy pusta tablice o podanym rozmiarze(lub nie jesli niepoprawne dane)
    }
    catch (std::bad_alloc)
    {
        std::cerr << "!"; //wypisuje blad gdy nie mozna stworzyc tablicy
        exit(0); //konczy dzialanie programu
    }
    return tablica; //zwraca wskaznik do tablicy
}

int podciag_max(int t[], int n)
{
	int max = 0; //maksymalna suma podciagu
	int temps = 0; //tymczasowa suma
	for (int i = 0; i < n; i++) //zlozonosc liniowa
	{
		temps = temps + t[i]; //dodaje do tymczasowej sumy kolejny element
		if (temps > max) //gdy znaleziono nowa maksymalna wartosc
		{
			max = temps; //nowa maksymalna wartosc jest ogolnym maxem
		}
		if (temps < 0) //jesli suma jest ujemna to suma = 0 (wtedy podciag pusty jest wiekszy)
		{
			temps = 0;
		}
	}
	
    return max;
}


int szuk_max(int** dane, int wiersze, int kolumny)
{
    int maxSum = 0; //deklaruje maksymalna wartosc jako 0(pusta tablica)

    int lewa, prawa, i;
    int* temp = nullptr;
    int sum;
    temp = tworzenie_tablicy1D(wiersze); //tworzy tymczasowa tablice o rozmiarze ilosci wierszy(rozmiar kolumn)

    // ustawiamy lewa kolumne na 0 i iterujemy przez wszystkie kolumny zaczynajac od lewej jako punktu startowego
    for (lewa = 0; lewa < kolumny; lewa++)
    {
        memset(temp, 0, wiersze * sizeof(int)); //ustawia wartosci tablicy dynamicznej na 0
          
        for (prawa = lewa; prawa < kolumny; prawa++) //ustawia prawa kolumne na lewa i iteruje przez przedzial lewa->prawa
        {

            for (i = 0; i < wiersze; i++)//wypelnia tymczasowa tablice liczbami z kolumny o numerze "prawa" dodajac kolejne jej elementy
            {
                temp[i] += dane[i][prawa];

            }


            //po dodaniu kolumn do siebie by stworzyc jeden tymczasowa tablice wywoluje funkcje szukania najwiekszego podciagu 1D 
            sum = podciag_max(temp, wiersze); //zwraca sume najwiekszego podciagu z tymczasowej tablicy
            
            if (sum > maxSum) //jesli obecna suma jest wieksza od poprzedniej to ustaw ja jako nowa sume
            {
                maxSum = sum;
            }
        }

    }
    delete[] temp; //zwalnia pamiec tablicy tymczasowej
    return maxSum;
}

int main()
{
    int z; //ilosc wywolan
    cin >> z;
    int licz;
    int* wyniki = nullptr;
    wyniki = tworzenie_tablicy1D(z); //tablica by pod koniec wypisac wszystkie wyniki naraz

    for(licz = 0; licz<z; licz++)
    {

        int wiersze, kolumny;
        string s;
        getline(cin>>ws, s); //zczytuje wymiary tablicy
        stringstream ss;
        ss << s; //zczytuje dane ze stringa do stringstreama
        ss >> wiersze; //ilosc wierszy (dlugosc kolumny)
        ss >> kolumny; //ilosc kolumn (dlugosc wierszy)
        if (kolumny < 1 || wiersze < 1 || kolumny > 100 || wiersze > 100) //zakoncz dzialanie jesli nie sa spelnione wymagania zadania
        {
            exit(0);
        }
        ss.clear(); //czysci bufor
        int** dane = nullptr;

        dane = tworzenie_tablicy2D(wiersze); //tworzy tablice wskaznikow
        for (int i = 0; i < wiersze; i++)
        {
            dane[i] = tworzenie_tablicy1D(kolumny); //tworzy wskazniki to tablic
            getline(cin>>ws, s); //zczytuje wartosci macierzy linijka po linijce
            ss << s;
            for (int j = 0; j < kolumny; j++)
            {
                ss >> dane[i][j]; //wczytuje dane ze stringstreamu do macierzy
                if(dane[i][j]<(-pow(2, 15)) || dane[i][j]>pow(2, 15)) //jesli warunki nie sa spelnione zakoncz dzialanie
                {
                    exit(0);
                }
            }
            ss.clear(); //czysci bufor 

        }

        wyniki[licz]=szuk_max(dane, wiersze, kolumny); //wynik dzialania algorytmu zapisywany jest do tabeli z wynikami
        for (int i = 0; i < wiersze; i++)
        {
            delete[] dane[i]; //czysci wiersze tablicy dynamicznej
        }
        delete[] dane; //czysci kolumny wskaznikow tablicy dynamicznej
    }
    cout << endl; //by jakis odstep przed wynikiem byl
    for (licz = 0; licz < z; licz++) //wypisuje wynik z tabeli
    {
        cout << wyniki[licz] << endl;
    }
        return 0;
}