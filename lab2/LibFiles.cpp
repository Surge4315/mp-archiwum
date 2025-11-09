#include "LibFiles.h"
#include <iostream>
#include <fstream>
#include <iomanip>
using namespace std;

//w tym pliku s¹ funkcje operuj¹ce na plikach

void test_nazwy(std::string nazwa_nieznany) 
{
    size_t dl = nazwa_nieznany.length();

    if (dl > 4) //.txt to 4 znaki wiec musi byc przynajmniej 5 by plik mial nazwe 
    {   //sprawdza czy plik ma rozszerzenie .txt
        if (nazwa_nieznany[dl - 4] == '.' || nazwa_nieznany[dl - 3] == 't' || nazwa_nieznany[dl - 2] == 'x' || nazwa_nieznany[dl - 1] == 't')
        {
            return; //jak wszystko ok to konczy funkcje
        }
        else
        {
            cerr << "plik musi miec rozszerzenie .txt!";
            cin.ignore();
            exit(0);
        }

    }
    else
    {
        cerr << "bledna nazwa pliku!";
        cin.ignore();
        exit(0);
    }
}

void zczytywanie_wspolrzednych(long double** tablica, int wiersze)
{
    string nazwa_nieznany;
    cin >> nazwa_nieznany;
    test_nazwy(nazwa_nieznany); //sprawdza poprawnosc pliku
    ifstream we;
    we.open(nazwa_nieznany); 
    if (!we.is_open()) //sprawdzanie czy plik otwarty
    {
        cerr << "nie mozna otworzyc pliku!";
        exit(0);
    }

    for (int j = 0; j < wiersze; j++)
    {
        for (int i = 0; i < 106; i++)
        {
            
                we >> tablica[j][i]; //wczytuje dane do tablicy wspolrzednych
        }

    }
    we.close();
}
void wypisywanie_tabeli(long double** siatka, ofstream& wy, int j)
{
    for (int i = 0; i < 106; i++)
    {
        wy <<setprecision(10)<< siatka[j - 1][i] << "\t"; //wypisuje dane y do pliku wynikowego
    }
    wy << endl << endl;
    for (int i = 0; i < 106; i++)
    {
        wy << setprecision(10)<<siatka[j][i] << "\t"; //wypisuje dane x do pliku wynikowego
    }
}

long double liczenie_bledu(long double** nieznany, long double** siatka, int j)
{
    long double temp_mse=0; //tymczasowa zmienna do liczenia bledu pomiarowego
    for (int i = 6; i < 106; i++)
    {
        temp_mse += pow((nieznany[0][i] - siatka[j - 1][i]), 2); //(y-y')^2
        temp_mse += pow((nieznany[1][i] - siatka[j][i]), 2); //(x-x')^2

    }
    return sqrt(temp_mse); //zwraca pierwiastek z sumy sumy szeregow
}

void wyznacz_przybliz(long double** nieznany, long double** siatka)
{
       ofstream wy;
       wy.open("wyniki.txt");
       if (!wy.is_open())
       {
           cerr << "nie mozna utworzyc pliku z wynikami!";
           exit(0);
       }
       int min_indeks; //indeks gdzie jest najmniejszy blad pomiarowy
       long double min_mse;//minimalny blad pomiarowy
       long double temp_mse; //tymczasowa zmienna do liczenia bledu pomiarowego
       for (int j = 1; j < 162; j += 2) //iterujemy przez siatki co 2 linijki
       {
            
           temp_mse = liczenie_bledu(nieznany, siatka, j);
            wy << temp_mse << " ";//wypisuje blad pomiarowy do pliku
            if (j == 1)
            {
                min_mse = temp_mse; //pierwsze wyliczone minimum jest na pewno najmniejsze
                min_indeks = 1;
            }
            if (temp_mse < min_mse) //sprawdza czy mamy nowy min blad
            {
                    min_mse = temp_mse; //jesli tak to go ustaw nowym min bledem
                    min_indeks = j; //numer indeksu gdzie jest najdokladniejsze przyblizenie 
            }
            temp_mse = 0; //zerujemy tymczasowy blad by moc od nowa liczyc
       }
       wy << endl << endl << "najmniejszy bled wynosi: " << min_mse << endl << endl << "dane i wspolrzedne Y X najbardziej dokladnego modelu:"<<endl<<endl;

       wypisywanie_tabeli(siatka, wy, min_indeks);
       wy.close();
       return;
}

