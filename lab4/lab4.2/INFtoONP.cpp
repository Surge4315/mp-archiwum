#include <iostream>
#include <stack>
#include "INFtoONP.h"
using namespace std;


int INF_priorytet(char operat) //priorytet operatorow (zgodnie z tabela)
{
    if (operat == '=')
        return 0;

    if (operat == '<' || operat == '>')
        return 1;

    if (operat == '+' || operat == '-')
        return 2;

    if (operat == '*' || operat == '/' || operat == '%')
        return 3;

    if (operat == '^')
        return 4;

    if (operat == '~')
        return 5;

    return -1; //jesli brak operatora zwroc -1
}

void INF_zbedne(string& dzialanie)
{
    for (int i = 0; i < dzialanie.size();)
    {
        if (INF_priorytet(dzialanie[i]) != -1 ||dzialanie[i] == ')' || dzialanie[i] == '(' || dzialanie[i] >= 'a' && dzialanie[i] <= 'z')
        {
            i++;//jesli element jest akceptowalny to sprawdz kolejny
        }
        else
        {
            dzialanie.erase(i, 1);//jesli element nie jest akceptowalny to go usun
        }
    }
}

bool INF_lacznosc(char operat) //0 - prawy, 1 - lewy
{
    if (operat == '=')
        return 0;

    if (operat == '<' || operat == '>')
        return 1;

    if (operat == '+' || operat == '-')
        return 1;

    if (operat == '*' || operat == '/' || operat == '%')
        return 1;

    if (operat == '^')
        return 0;

    if (operat == '~')
        return 0;
}

string INF_konwersja_do_ONP(string infix)
{
    int i = 0;
    string ONP = ""; //wynik koncowy, na razie pusty
    int nawiasy_r=0, nawiasy_l=0; //wystapienia nawiasow prawych i lewych do sprawdzania poprawnosci nawiasow
    bool ile_liter = 0;//liczy wystapienia po sobie liter (max 1 inaczej blad)
    stack <int>stos; //wykorzystujemy wbudowany stos

    while (infix[i] != '\0') //do czasu az nie dotrzemy do znaku konca stringu
    {
        // jesli operand (literki) to dodaj go do stosu z wyrazeniem onp
        if (infix[i] >= 'a' && infix[i] <= 'z')
        {
            if (ile_liter)//jesli poprzednim znakiem byla litera a obecnym  tez jest litera to zwroc blad
            {
                return "error";
            }
            ONP += infix[i];
            i++;
            ile_liter = 1;
        }
        // jesli nawias otwierajacy to dodaj na stack
        else if (infix[i] == '(')
        {
            stos.push(infix[i]);
            i++;
            nawiasy_l++;//zwiekszamy ilosc lewych nawiasow o 1
            ile_liter = 0;
        }
        // jesli nawias zamykajacy
        else if (infix[i] == ')')
        {
            nawiasy_r++;//zwiekszamy ilosc prawych nawiasow o 1
            if (nawiasy_r > nawiasy_l)//jesli ilosc zamknietych nawiasow jest wieksza od ilosci otwartych nawiasow
            {
                return "error"; // zwracamy blad i konczymy program
            }
            while (stos.top() != '(') { //do czasu az na szczycie stosu nie ma nawiasu otwierajacego sciagamy elementy ze stosu
                ONP += stos.top(); //dodajemy sciagane elementy do wyrazenia ONP
                stos.pop();
            }
            stos.pop(); //sciagamy nawias otwierajacy
            i++;
            ile_liter = 0;
        }
        else
        {
            if (INF_priorytet(infix[i]) == -1) //jesli znak jest nieznany wypisz blad
            {
                return "error";
            }
            if (INF_lacznosc(infix[i])) //jesli lacznosc lewostronna (<=)
            {
                while (!stos.empty() && INF_priorytet(infix[i]) <= INF_priorytet(stos.top()))//dopoki stos nie jest pusty a sprawdzany element jest mniej lub rownie wazny co ten na szczycie stosu
                {
                    ONP += stos.top(); //sciagnij element ze stosu i dodaj do wyniku
                        stos.pop();
                }
                stos.push(infix[i]); //dodaj badany element na stos
                    i++;
                   
            }
            else//jesli lacznosc prawostronna (<)
            {
                while (!stos.empty() && INF_priorytet(infix[i]) < INF_priorytet(stos.top()))//dopoki stos nie pusty a badany element mniej wazny od szczytu stosu
                {
                    ONP += stos.top();//sciagnij element z gory i dodaj do wyniku
                    stos.pop();
                }
                stos.push(infix[i]);//dodaj badany element na stos
                i++;
                if (INF_priorytet(infix[i - 1]) == 5 && INF_priorytet(infix[i]) == 5) //jesli mamy operator "~~" to dodajemy drugi ~ na stos
                {
                    stos.push(infix[i]);
                    i++;
                }
                
            }
            ile_liter = 0; //resetujemy licznik powtarzajacyh sie liter liter
        }
    }
    //przeniesienie pozostalych elementow ze stosu do wyniku
    while (!stos.empty()) {
        ONP += stos.top();
        stos.pop();
    } 
    return ONP;
}
