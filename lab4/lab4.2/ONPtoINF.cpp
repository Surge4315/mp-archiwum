#include <iostream>
#include <stack>
#include <string>
#include "ONPtoINF.h"
using namespace std;

int ONP_priorytet(char operat) //priorytet operatorow (zgodnie z tabela)
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

void ONP_zbedne(string &dzialanie)//funkcja szuka zbednych elementow 
{
    for (int i = 0; i < dzialanie.size();)
    {
        if (ONP_priorytet(dzialanie[i])!=-1 || dzialanie[i] >= 'a' && dzialanie[i] <= 'z')
        {
            i++;//jesli element jest akceptowalny to sprawdz kolejny
        }
        else
        {
            dzialanie.erase(i, 1);//jesli element nie jest akceptowalny to go usun
        }
    }

    


}



bool ONP_czyoperand(char x)
{
    return (x >= 'a' && x <= 'z');
}

bool ONP_next_priorytet(string dzialanie, int i, int waznosc)
{
    // np dla ab+cdef+++/ by bylo (a+b)/....
    i = i + 1;//element nastepny
    //w skrocie liczymy znaki dopoki nie natrafimy na znak ktory dotyczy obecnego rownania
    int ile_operandow = 0;
    int ile_operatorow= 0;
    for (i; dzialanie[i] != '\0'; i++)
    {
        if (ONP_czyoperand(dzialanie[i]))
        {//ilosc dzialan do wykonania a ile zostalo liter
            ile_operandow++; //nowy operator
        }
        else if (dzialanie[i] == '~')
        {
            //pomin wichajster
        }
        else
        {
            ile_operatorow++;
        }
        //jesli mamy element nastepny ktory nas dotyczy (albo ilosc elementow jest rowna albo od razu nastepny jest operator) 
        if ((ile_operatorow) == ile_operandow || (ile_operandow==0 && ile_operatorow==1))
        {
            if (ONP_priorytet(dzialanie[i]) > waznosc)
            {
                return 1;
            }
            break;
        }
    }
    return 0;
}





string ONP_konwersja_do_INF(string dzialanie)
{
    stack<string> infix; 
    for (int i = 0; dzialanie[i] != '\0'; i++) {
        if (ONP_czyoperand(dzialanie[i]))//jesli operand to zrob z niego osobny string i dodaj na stos
        {
            string op(1, dzialanie[i]);
            infix.push(op);
        }
        else if (dzialanie[i] == '~') //sprawa wichajstra, wichajster nigdy nie ma nawiasow
        {
            string wichajster = "~"; //gdybym po prostu wypisal dzialanie[i] to wypisuje jakies range f bzdety
            string op = infix.top(); //gornym elementem stosu zostaje op (operand)
            infix.pop(); //sciagamy ze stosu gorny element
            if (dzialanie[i + 1] == '~') //gdyby byly dwa
            {
                infix.push(wichajster + wichajster + op);//zwracamy na stos gorny wyraz z dodanymi dwoma wichajstrami
                i++;
            }
            else //jesli jeden wichajster
            {
                infix.push(wichajster + op);//zwracamy na stos gorny wyraz z jednym wichajstrem
            }
        }
        else
        {
            
            string op1 = infix.top();
            infix.pop();
            if (infix.empty())//jesli stos jest juz pusty a probujemy cos z niego zdjac to error
            {
                return "error";
            }
            string op2 = infix.top();
            infix.pop();
            if (ONP_priorytet(dzialanie[i])==-1) //jesli bledny znak to error
            {
                return "error";
            }
            else if (ONP_czyoperand(dzialanie[i + 1]) && !ONP_next_priorytet(dzialanie, i, ONP_priorytet(dzialanie[i])) || dzialanie[i+1]=='\0')//jesli nastepna jest litera lub koniec wyrazenia to brak nawiasow
            {
                infix.push(op2 + dzialanie[i] + op1);   
            }
            else if (ONP_priorytet(dzialanie[i])==ONP_priorytet(dzialanie[i+1]))//pierwszy element z serii tych samych dzialan(znakow kolo siebie) ma nawiasy
            {
                infix.push('(' + op2 + dzialanie[i] + op1 + ')');
            }
            else if (ONP_next_priorytet(dzialanie, i, ONP_priorytet(dzialanie[i])))//obecny element jest mniej wazny od nastepnego
            {
                infix.push('(' + op2 + dzialanie[i] + op1 + ')');   
            }
            else //jesli zaden warunek nie zostal spelniony to bez nawiasow
            {
                infix.push(op2 + dzialanie[i] + op1);               
            }
        }
    }
    return infix.top(); //zwracamy ze szczytu stosu gotowy wynik
}
