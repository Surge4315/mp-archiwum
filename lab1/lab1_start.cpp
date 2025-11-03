#include <iostream>
#include <cmath>
using namespace std;

int* tworzenie_tablicy(int rozmiar) //tworzy tablice o danym rozmiarze
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

int suma(int liczba)
{
		if (liczba > 0) //jesli liczba dodatnia to zwroc jej trzykrotnosc
		{
			return 3 * liczba;

		}
		else //jesli liczba niedodatnia to zwroc jej dwukrotnosc
		{
			return 2 * liczba;
		}
	
}

void wypisz_max(int t[], int n)
{
	int max = 0; //maksymalna suma podciagu
	int temp = 0; //tymczasowa suma
	int start = 0; //start podciagu
	int start_temp = 0;//tymczasowy start gdy zaczynamy nowy podciag
	int koniec = 0; //koniec podciagu
	for (int i = 0; i < n; i++) //zlozonosc liniowa
	{
		temp = temp + suma(t[i]); //dodaje do tymczasowej sumy kolejny element
			if (temp > max) //gdy znaleziono nowa maksymalna wartosc
			{
				max = temp;
				koniec = i;
				start = start_temp;
			}
			if (temp < 0) //jesli suma jest ujemna to suma = 0 (wtedy podciag pusty jest wiekszy)
			{
				temp = 0;
				start_temp = i+1; //zaczyna nowy podciag od kolejnego elementu (ale wprowadzony nie-tymczasowo zostanie gdy pojawi się nowy max)
			}
		}
	if (t[0] < 0 && start == 0 && koniec == 0) //jesli wszystkie wartosci ciagu sa ujemne to ciag pusty
	{
		cout << max<<endl; //wypisuje tylko max bo podciag pusty nie ma poczatku ani konca 
	}
	else
	{
		cout << start << " " << koniec << " " << max << endl;
	}
}




int main()
{
	int z; //liczba zestawow danych
	cin >> z; //wczytuje dowolne 'z' (liczba ujemna/zero nie wywola petli)
	for (int i = 0; i < z; i++)
	{
		int* dane = nullptr;
		int n; //rozmiar tablicy
		int temp_dane; //tymczasowe wartosci tablicy
		cin >> n;
		if (n<1 || n>pow(10, 6)) //sprawdza czy wielkosc tablicy jest odpowiednia
		{
			exit(0); //jak nie to konczy dzialanie
		}
		dane = tworzenie_tablicy(n); //dane zostal pusty ciag o rozmiarze 'n'
		for (int j = 0; j < n; j++)
		{
			cin >> temp_dane;//wczytuje podane liczby do ciagu
			if (abs(temp_dane) > 2000)
			{
				exit(0); //jesli za duza liczba to konczy dzialanie
			}
			dane[j] = temp_dane; //wczytuje dane po sprawdzeniu do tablicy
		}
		wypisz_max(dane, n); //wywolanie funkcji wyznaczajacej podciag
		delete[] dane; //czysci tablice by moc ja wykorzystac w kolejnym zestawie
	}
}
