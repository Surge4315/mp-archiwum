#ifndef INTTOONP_H_
#define INTTOONP_H_
#include <iostream>
#include <string>

/*
* funkcja wyznacza priorytet operarora
* @param operat - znak ktorego priorytet wyznaczamy
* @return liczba priorytetu
*/
int INF_priorytet(char operat);

/*
* funkcja usuwa zbedne znaki ze stringu
* @param &dzialanie - referencja do dzialania ktoremu usuwamy zbedne znaki
*/
void INF_zbedne(std::string& dzialanie);

/*
* funkcja sprawdza lacznosc operatora
* @param operat - operator ktorego lacznosc sprawdzamy
* @return 1 - lewostronny 0 - prawostronny 
*/
bool INF_lacznosc(char operat);

/*
* funkcja konwertuje z INF do ONP
* @param infix - dzialanie w notacji infiksowej
* @return dzialanie w ONP
*/
std::string INF_konwersja_do_ONP(std::string infix);

#endif