#include "Lib_Z3.h"
#include <iostream>
#include <fstream>

void Z_zakres215(int n)
{
    if (n<1 || n>pow(2, 15)) //sprawdza czy ilosc serii danych jest poprawna
    {
        std::cerr << "zla ilosc serii danych!";
        exit(0);
    }
}

void Z_zakres248(int n)
{
    if (n<(-pow(2, 48)) || n>pow(2, 48)) //sprawdza czy ilosc serii danych jest poprawna
    {
        std::cerr << "zly rozmiar danych!";
        exit(0);
    }
}

int ilosc(int* tablica, int rozmiar, int indeks)
{
	
	
	int count = 1; //ilosc poczatkowa wynosi 1
	int i = (indeks - 1); //element na lewo od znalezionego
	while (i >= 0 && tablica[i] == tablica[indeks])
	{
		count++; //zwieksza ilosc wystapien o 1
		i--; //sprawdza kolejny element po lewo
	}
	i = (indeks + 1); //element na prawo od znalezionego
	while (i < rozmiar && tablica[i] == tablica[indeks])
	{
		count++,  //zwieksza ilosc wystapien o 1
			i++; //sprawdza kolejny element na prawo
	}
	return count; //zwraca ilosc wystapien
}

int Z_ile_wystapien(int* tablica, int rozmiar, int szukana)
{
	



	//l - lewy index tablicy, p - prawy index tablicy
	{
		int sr;
		int l = 0; //lewy indeks(poczatek tablicy)
		int p = rozmiar - 1; //prawy indeks(koniec tablicy)
		while (l <= p)
		{
			sr = (l + p) / 2; //srodek przeszukiwanej tablicy

			if (tablica[sr] == szukana)//sr jest okolo srodkowym elementem jesli sie powtarzaja wartosci
				return ilosc(tablica, rozmiar, sr); //dlatego trzeba recznie ich ilosc policzyc


			if (tablica[sr] > szukana)
				p = sr - 1; //nowy prawy indeks (szukamy na lewo od srodkowej wartosci)
			else
				l = sr + 1; //nowy lewy indeks (szukamy na prawo od srodkowej wartosci)
		}

		return 0; //zwracamy 0, gdy nie znajdziemy elementu
	}
}

int Z_interpolacja(int* tablica, int rozmiar, int szukana)
{
	int is = -1; //indeks szukanej liczby
	int s = szukana; //szukana wartosc
	int ip = 0; //indeks pierwszego elementu
	int ik = rozmiar-1; //indeks ostatniego elementu
	while (tablica[ip] <= s && s <= tablica[ik])
	{
		is = ((((s - tablica[ip]) * (ik - ip)) / (tablica[ik] - tablica[ip])) + ip); //nowy srodek tabeli
		if (tablica[is] == szukana) //jesli znaleziono element to go zwroc
		{
			return is;
		}
		else if (szukana < tablica[is]) //jesli element wyszukany jest wiekszy to szukamy w mniejszych elementach
			ik = is - 1;
		else
			ip = is + 1; //jesli element wyszukany jest mniejszy to szukamy w wiekszych
	}
	return is; //jesli nie znaleziono to zwroc is = -1

}

void Z_bezpowt(int* tablica, int rozmiar, std::ofstream& wy)
{

	wy << tablica[0] << " "; //pierwszy element na pewno nie ma przed soba powtorzen
	int ile_wyp = 1;//ilosc wypisanych elementow
	for (int i = 1; i < rozmiar; i++)
	{
		
		if ((ile_wyp) % 50 == 0) //co 50 elementow nowy wiersz
		{
			wy << std::endl;
		}
		if (tablica[i] != tablica[i - 1]) //jesli sie nie powtarza to wypisz
		{
			wy << tablica[i] << " ";
			ile_wyp++;//zwieksza licznik wypisanych elementow
		}
		if (ile_wyp == 200) //jesli wypisano 200 elementow zakoncz dzialanie petli
		{
			break;
		}
		
	}

}
