#include<iostream>
#include <bitset>
#include <sstream>
#include "klasa.h"
using std::string; using std::cout; using std::endl;


void systems::hex_dec(string dana){

    liczba_int = {};
    for (int i = 0; i < dana.length(); i++) {

        if (dana[i] >= 48 && dana[i] <= 57) {
            liczba_int += ((dana[i]) - 48) * pow(16, dana.length() - i - 1);
        }

        else if (dana[i] >= 65 && dana[i] <= 70) {
            liczba_int += ((dana[i]) - 55) * pow(16, dana.length() - i - 1);
        }

        else if (dana[i] >= 97 && dana[i] <= 102) {
            liczba_int += ((dana[i]) - 87) * pow(16, dana.length() - i - 1);
        }
        else {
            liczba_int = {};
            break;
        }
    }
}

void systems::hex_bin(string dana) {
    int check = 0;
    liczba_bin = {};
	for (int i = 0; i < dana.length(); i++) {

        switch (toupper(dana[i])) {

        case '0': liczba_bin += "0000 ";break;
        case '1': liczba_bin += "0001 ";break;
        case '2': liczba_bin += "0010 ";break;
        case '3': liczba_bin+= "0011 "; break;
        case '4': liczba_bin+= "0100 "; break;
        case '5': liczba_bin+= "0101 "; break;
        case '6': liczba_bin+= "0110 "; break;
        case '7': liczba_bin+= "0111 "; break;
        case '8': liczba_bin+= "1000 "; break;
        case '9': liczba_bin+= "1001 "; break;
        case 'A': liczba_bin+= "1010 "; break;
        case 'B': liczba_bin+= "1011 "; break;
        case 'C': liczba_bin+= "1100 "; break;
        case 'D': liczba_bin+= "1101 "; break;
        case 'E': liczba_bin+= "1110 "; break;
        case 'F': liczba_bin+= "1111 "; break;
        default: liczba_bin = {}; check = 1;  break;

        }
        if (check)
            break;
	}
}

void systems::bin_dec(string dana) {
    liczba_int = {};
    for (int i = 0; i < dana.length(); i++) {

        if (dana[i] == '1') {
            liczba_int += pow(2, dana.length() - i - 1);
        }
        else if (dana[i] == '0') {}            
        else{
            liczba_int = {};
            break;
        }
    }

}

void systems::bin_hex(string dana) {
    liczba_hex = {};

    std::bitset<32> set(dana);
    std::stringstream aha;
    aha << std::hex << std::uppercase << set.to_ulong();
    liczba_hex = aha.str();

}


void systems::dec_bin(string dana) {
    liczba_bin = {};

    int dana_in = stoi(dana);
    char tab[2] = { '0','1' };
    int sp = 0;
    if (dana_in == 0)
        liczba_bin += tab[0];
    while (dana_in > 0) {
        sp++;
        liczba_bin += tab[dana_in % 2];
        dana_in /= 2;
        if (sp % 4 == 0)
            liczba_bin += ' ';
        
    }
    reverse(liczba_bin.begin(), liczba_bin.end());



}



void systems::dec_hex(string dana) {
    liczba_hex = {};

    int dana_in = stoi(dana);
    char tab[16] = { '0','1','2','3','4','5','6','7','8','9','A','B','C','D','E','F' };
    if (dana_in == 0) 
        liczba_hex += tab[0];
    
    while (dana_in > 0) {

        liczba_hex += tab[dana_in % 16];
        dana_in /= 16;

    }
    reverse(liczba_hex.begin(), liczba_hex.end());
}


void conversion(string dana , systems &wynik) {

	if (dana[1] == 'x' || dana[1] == 'X') {
		dana.erase(0, 2);
		wynik.hex_dec(dana);
		wynik.hex_bin(dana);
        cout << "HEX:" << dana << endl;
        cout <<"DEC:" << wynik.get_liczba_int() << endl;
        cout <<"BIN:" << wynik.get_liczba_bin() << endl;
	}
	else if (dana[1] == 'b' || dana[1] == 'B') {
		dana.erase(0, 2);
		wynik.bin_dec(dana);
		wynik.bin_hex(dana);
        cout << "BIN:" << dana << endl;
        cout << "DEC:" << wynik.get_liczba_int() << endl;
        cout << "HEX:" << wynik.get_liczba_hex() << endl;
	}
	else {
		wynik.dec_bin(dana);
		wynik.dec_hex(dana);
        cout << "DEC:" << dana << endl;
        cout << "BIN:" << wynik.get_liczba_bin() << endl;
        cout << "HEX:" << wynik.get_liczba_hex() << endl;
	}

}

void calculation(string dana, systems& wynik, systems& wynik2){
    string dana1 = {};
    string dana2 = {};
    int i = 0;

    while (dana[i] != '+' && dana[i] != '-' && dana[i] != '*' && dana[i] != '/' ) 
        i++;
    dana1 = dana.substr (0, i);
    dana2 = dana.substr(i+1);

    switch (dana1[1]) {
        
        case 'x':
        case 'X':
            dana1.erase(0, 2);
            wynik.hex_dec(dana1);
            break;
        case 'b':
        case 'B':
            dana1.erase(0, 2);
            wynik.bin_dec(dana1);
            break;
        default:
            int temp = std::stoi(dana1);
            wynik.set_liczba_int(temp);
    }

    switch (dana2[1]) {

        case 'x':
        case 'X':
            dana2.erase(0, 2);
            wynik2.hex_dec(dana2);
            break;
        case 'b':
        case 'B':
            dana2.erase(0, 2);
            wynik2.bin_dec(dana2);
            break;
        default:
            int temp = std::stoi(dana2);
            wynik2.set_liczba_int(temp);
    }

    if (dana[i] == '+') {
        string dodaj = std::to_string(wynik.get_liczba_int() + wynik2.get_liczba_int());
        wynik.dec_bin(dodaj);
        wynik.dec_hex(dodaj);
        cout << "DEC:" << dodaj << endl;
        cout << "BIN:" << wynik.get_liczba_bin() << endl;
        cout << "HEX:" << wynik.get_liczba_hex() << endl;
    }
    else if (dana[i] == '-') {
        string dodaj = std::to_string(wynik.get_liczba_int() - wynik2.get_liczba_int());
        wynik.dec_bin(dodaj);
        wynik.dec_hex(dodaj);
        cout << "DEC:" << dodaj << endl;
        cout << "BIN:" << wynik.get_liczba_bin() << endl;
        cout << "HEX:" << wynik.get_liczba_hex() << endl;
    }
    else if (dana[i] == '*') {
        string dodaj = std::to_string(wynik.get_liczba_int() * wynik2.get_liczba_int());
        wynik.dec_bin(dodaj);
        wynik.dec_hex(dodaj);
        cout << "DEC:" << dodaj << endl;
        cout << "BIN:" << wynik.get_liczba_bin() << endl;
        cout << "HEX:" << wynik.get_liczba_hex() << endl;
    }
    else if (dana[i] == '/') {
        string dodaj = std::to_string(wynik.get_liczba_int() / wynik2.get_liczba_int());
        wynik.dec_bin(dodaj);
        wynik.dec_hex(dodaj);
        cout << "DEC:" << dodaj << endl;
        cout << "BIN:" << wynik.get_liczba_bin() << endl;
        cout << "HEX:" << wynik.get_liczba_hex() << endl;
    }
    

}

void calculation2(string dana, systems& wynik, systems& wynik2) {
    string dana1 = {};
    string dana2 = {};
    int i = 0;
    int tylda = 0;
    while (dana[i] != '&' && dana[i] != '|' && dana[i] != '^' && dana[i] != '~')
        i++;

    if (dana[i] == '~')
        tylda = 1;

    dana1 = dana.substr(0, i);

    switch (dana1[1]) {

    case 'x':
    case 'X':
        dana1.erase(0, 2);
        wynik.hex_dec(dana1);
        break;
    case 'b':
    case 'B':
        dana1.erase(0, 2);
        wynik.bin_dec(dana1);
        break;
    default:
        int temp = std::stoi(dana1);
        wynik.set_liczba_int(temp);
    }

    if (!tylda) {
        dana2 = dana.substr(i + 1);
        switch (dana2[1]) {

        case 'x':
        case 'X':
            dana2.erase(0, 2);
            wynik2.hex_dec(dana2);
            break;
        case 'b':
        case 'B':
            dana2.erase(0, 2);
            wynik2.bin_dec(dana2);
            break;
        default:
            int temp = std::stoi(dana2);
            wynik2.set_liczba_int(temp);
        }


        if (dana[i] == '&') {
            string dodaj = std::to_string(wynik.get_liczba_int() & wynik2.get_liczba_int());
            wynik.dec_bin(dodaj);
            wynik.dec_hex(dodaj);
            cout << "DEC:" << dodaj << endl;
            cout << "BIN:" << wynik.get_liczba_bin() << endl;
            cout << "HEX:" << wynik.get_liczba_hex() << endl;
        }
        else if (dana[i] == '|') {
            string dodaj = std::to_string(wynik.get_liczba_int() | wynik2.get_liczba_int());
            wynik.dec_bin(dodaj);
            wynik.dec_hex(dodaj);
            cout << "DEC:" << dodaj << endl;
            cout << "BIN:" << wynik.get_liczba_bin() << endl;
            cout << "HEX:" << wynik.get_liczba_hex() << endl;
        }
        else if (dana[i] == '^') {
            string dodaj = std::to_string(wynik.get_liczba_int() ^ wynik2.get_liczba_int());
            wynik.dec_bin(dodaj);
            wynik.dec_hex(dodaj);
            cout << "DEC:" << dodaj << endl;
            cout << "BIN:" << wynik.get_liczba_bin() << endl;
            cout << "HEX:" << wynik.get_liczba_hex() << endl;
        }
    }
    else {
        string dodaj = std::to_string(~ wynik.get_liczba_int());
        wynik.dec_bin(dodaj);
        wynik.dec_hex(dodaj);
        cout << "DEC:" << dodaj << endl;
        cout << "BIN:" << wynik.get_liczba_bin() << endl;
        cout << "HEX:" << wynik.get_liczba_hex() << endl;

    }
}

string systems::get_liczba_hex() { return liczba_hex; }
string systems::get_liczba_bin() { return liczba_bin; }
int systems::get_liczba_int() { return liczba_int; }

void systems::set_liczba_hex(string liczba_hex_) { liczba_hex = liczba_hex_; }
void systems::set_liczba_bin(string liczba_bin_) { liczba_bin = liczba_bin_; }
void systems::set_liczba_int(int liczba_int_) { liczba_int = liczba_int_; }