#ifndef ONPTOINF_H_
#define ONPTOINF_H_
#include <stack>
#include <iostream>
#include <string>

/*
* funkcja wyznacza priorytet operarora
* @param znak - znak ktorego priorytet wyznaczamy
* @return liczba priorytetu
*/
int ONP_priorytet(char znak);

/*
* funkcja usuwa zbedne znaki ze stringu
* @param &dzialanie - referencja do dzialania ktoremu usuwamy zbedne znaki
*/
void ONP_zbedne(std::string &dzialanie);

/*
* funkcja sprawdza czy znak jest operandem
* @param znak - sprawdzany znak
* @return prawda lub fa³sz
*/
bool ONP_czyoperand(char znak);

/*
* funkcja konwertuje z ONP do INF
* @param dzialanie - dzialanie do konwersji w formacie ONP
* @return dzialanie po konwersji w formacie INF
*/
std::string ONP_konwersja_do_INF(std::string dzialanie);

#endif