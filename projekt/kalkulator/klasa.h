#ifndef klasa_h
#define klasa_h
#include<iostream>
using std::string;

class systems {
	private:
		int liczba_int = {};
		string liczba_bin = {};
		string liczba_hex = {};
	public:
		string get_liczba_hex();
		string get_liczba_bin();
		int get_liczba_int();

		void set_liczba_hex(string);
		void set_liczba_bin(string);
		void set_liczba_int(int);

		void hex_dec(string);
		void bin_dec(string);

		void dec_hex(string);
		void dec_bin(string);

		void bin_hex(string);
		void hex_bin(string);

};

void conversion(string , systems&);
void calculation(string, systems&, systems&);
void calculation2(string, systems&, systems&);

#endif 