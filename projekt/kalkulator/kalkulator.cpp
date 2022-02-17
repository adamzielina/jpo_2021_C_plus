//kalkulator.cpp : Ten plik zawiera funkcję „main”. W nim rozpoczyna się i kończy wykonywanie programu.
//Author: Adam Zielina


#include <iostream>
#include "klasa.h"
using std::cout; using std::cin; using std::string;

int main()
{
    systems wynik,wynik2;
    string tekst = {};
    while (1) {
        cout << "wybierz tryb pracy\nobliczenia arytmetyczne -> \"calc\" konwersja systemow -> \"conv\" lub obliczenia logiczne -> \"logic\"\n";
        cin >> tekst;
        if (tekst == "calc") {
            while (1) {
                cout << "prosze wpisac rownanie w postaci \"liczba1znakliczba2\" \nprzed wpisaniem liczby wybierz system '0x' '0b' lub 'NULL'\nznak to '+' '-' '*' '/'\nprzyklad: 0xa+0b1111\n[wpisz 'exit' aby wyjsc]\n";
                cin >> tekst;
                if (tekst == "exit")
                    break;
                else
                    calculation(tekst, wynik, wynik2);
            }
        }
        else if (tekst == "conv") {
            while (1) {
                cout << "podaj liczbe w postaci 'xliczba'\nprzed wpisaniem liczby wybierz system '0x' '0b' lub 'NULL'\nprzyklad: 0xa lub 0b1010 lub 1234\n[wpisz 'exit' aby wyjsc]\n";
                cin >> tekst;
                if (tekst == "exit")
                    break;
                else
                    conversion(tekst, wynik);
            }
        }
        else if (tekst == "logic") {
            while (1) {
                cout << "prosze wpisac rownanie w postaci \"liczba1znakliczba2\" lub \"liczba1~\" aby zanegowac\nprzed wpisaniem liczby wybierz system '0x' '0b' lub 'NULL'\nznak to '&' '|' '^'\nprzyklad: 0xa|0b1111 lub 0xa~\n[wpisz 'exit' aby wyjsc]\n";
                cin >> tekst;
                if (tekst == "exit")
                    break;
                else
                    calculation2(tekst, wynik, wynik2);
            }
        }
            
        else
            cout << "zly tryb\n";
    }
   
}
