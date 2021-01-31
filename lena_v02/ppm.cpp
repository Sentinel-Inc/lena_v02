﻿#include "ppm.h"

exception::invalid_file_format_exception invalid_file_format;
exception::invalid_character_exception invalid_character;
exception::bad_dimentions_exception bad_dimentions;
exception::bad_dimentions_exception bad_dimentions_ppm;
exception::invalid_path_exception invalid_path_ppm;
exception::invalid_file_format_exception invalid_file_format_ppm;
exception::invalid_character_exception invalid_character_ppm;
exception::not_implemented_file_format_exception not_implemented_file_format_ppm;
bool is_comment(const char& letter);
int read_number(std::fstream& plik);
void handle_char(std::fstream& plik);
void ignore_comment(std::fstream& plik);

ppm::ppm(const ppm& other)
{
	image = other.image;
	x = other.x;
	y = other.y;
	max_color = other.max_color;
}

ppm& ppm::operator=(const ppm& other)
{

	if (this == &other) return *this;
	image = other.image;
	x = other.x;
	y = other.y;
	max_color = other.max_color;
	return *this;
}


unsigned char ppm::check_color(int color) {
	if (color<0 || color>(int) max_color) {
		throw invalid_file_format_ppm;
	}
	else return (unsigned char)color;


}
format ppm::read_header(std::fstream& plik) {
	char letter;
	do {

		plik >> letter;
		if (is_comment(letter)) ignore_comment(plik);// w przypadu gdy napotkamy '#' czyli poczatek komentarza

		else if (letter == 'P') {
			plik >> letter;
			switch (letter) {
			case '3': return format(ascii);
				//wczytanie poprawnego naglowka (w tym przypadku P1)koonczy zadanie funkcji 

			case '6': return format(binary);
				//zwracany jest format w jakim zapisane sa dane w pliku

			default:
				//niepoprawne rozszerzenie pliku
				// lub napotkano na nioczekiwany symbol 

				throw invalid_file_format_ppm;
				break;
			}

		}
		else {
			//napotkano nioczekiwany symbol
			throw invalid_character_ppm;
		}

	} while (!plik.eof());
	throw invalid_file_format_ppm;
	// nie znaleziono naglowka pliku 

}


ppm::ppm(std::string file_path) {

	std::fstream plik;
	plik.open(file_path, std::ios::in);
	if (plik.good()) {

		if (read_header(plik) == format(ascii)) {


			x = read_number(plik);

			if (x < 0) { throw bad_dimentions_ppm; }//wysokosc musi byc nieujemna


			y = read_number(plik);


			if (y < 0) { throw bad_dimentions_ppm; }// szerokosc  musi byc nieujemna

			max_color = read_number(plik);

			if (max_color < 0 || max_color >255) { throw bad_dimentions_ppm; } //niebslugiwana rodzielczosc kolorww 

			unsigned array_size = y * x; // tymczasowa  zmienna

			image.reserve(array_size);



			for (unsigned i = 0; i < array_size; i++) {

				if (plik.eof()) { throw bad_dimentions_ppm; } //   nizgodny rozmiar pliku z zadeklarowanym rozmiarem zdjecia

				unsigned char R = check_color(read_number(plik));

				if (plik.eof()) { throw bad_dimentions_ppm; } //   nizgodny rozmiar pliku z zadeklarowanym rozmiarem zdjecia

				unsigned char G = check_color(read_number(plik));

				if (plik.eof()) { throw bad_dimentions_ppm; } //   nizgodny rozmiar pliku z zadeklarowanym rozmiarem zdjecia

				unsigned char B = check_color(read_number(plik));

				image[i].set_all(R, G, B);//dodaje pobrany kolor do tablicy

			}
		}
		else {
			// nie zaiplementowany format pliku w tym, przypadku p6
			throw  not_implemented_file_format_ppm;
		}
	}
	else {
		// nie znaleziono pliku pod podanym adresem lub napodkano problem z odczytaniem danych z niego
		//wiecej pod adresem: https://en.cppreference.com/w/cpp/io/basic_ios/good

		throw invalid_path_ppm;
	}
}


bool is_comment(const char& letter) { return letter == '#'; }


void ignore_comment(std::fstream& plik)
{
	// getline czyta znaki do koñca linijki
	// do tego celu deklaruje tymczasowa zmienna comment, ktora przechowywuje komentarz z pliku
	// oczywiscie jak na razie ta informacja nie jest do nieczego wykorzystywana 
	std::string comment;
	std::getline(plik, comment, '\n');

}


void handle_char(std::fstream& plik) {
	char letter;

	plik.clear(plik.goodbit); 

	plik >> letter; // ponownie wczytuje znak

	if (is_comment(letter)) ignore_comment(plik);
	else {

		throw invalid_character;
		//napotkano nioczekiwany symbol
	}


}


int read_number(std::fstream& plik) {
	int number;
	do {
		plik >> number;
		if (plik.fail()) handle_char(plik); // obiekt fstream gdy napotka nielegalny symbol wystawia blad
		//wiecej informacji : https://www.cplusplus.com/reference/ios/ios/rdstate/
		else return number;

	} while (!plik.eof());
	throw invalid_file_format;
	//plik nie posiada liczb albo ma ich za malo

}
