﻿#include "ppm.h"



exception::bad_dimentions_exception bad_dimentions_ppm;
exception::invalid_path_exception invalid_path_ppm;
exception::invalid_file_format_exception invalid_file_format_ppm;
exception::invalid_character_exception invalid_character_ppm;
exception::not_implemented_file_format_exception not_implemented_file_format_ppm;

extern bool is_comment(const char&);
extern void ignore_comment(std::fstream&);
extern void handle_char(std::fstream&);
extern int read_number(std::fstream&);

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




void ppm::set_pixel(size_t x, size_t y, pixel_24bit new_pixel)
{
	image[x * this->x + y] = new_pixel;
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
	read_data_from_file(file_path);

}
void ppm::read_data_from_file(std::string file_path)
{
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

			size_t array_size = y * x; // tymczasowa  zmienna

			if (!image.empty()) image.clear(); // jeżeli obraz posiada już dane 
							  // należy je nadpisać 
			image.reserve(array_size);


			for (unsigned i = 0; i < array_size; i++) {

				if (plik.eof()) { throw bad_dimentions_ppm; } //   nizgodny rozmiar pliku z zadeklarowanym rozmiarem zdjecia

				unsigned char R = check_color(read_number(plik));

				if (plik.eof()) { throw bad_dimentions_ppm; } //   nizgodny rozmiar pliku z zadeklarowanym rozmiarem zdjecia

				unsigned char G = check_color(read_number(plik));

				if (plik.eof()) { throw bad_dimentions_ppm; } //   nizgodny rozmiar pliku z zadeklarowanym rozmiarem zdjecia

				unsigned char B = check_color(read_number(plik));

				image.push_back({ R, G, B });//dodaje pobrany kolor do tablicy

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

void ppm::save_data_to_file(std::string file_path)
{

	std::fstream plik;
	plik.open(file_path, std::ios::out);
	plik << "P3\n";
	plik << x << "\n";
	plik << y << "\n";
	plik << max_color << "\n";

	plik << "#generated with lena_vo2";
	for (int i = 0; i < size() ; i++) {

		plik << image[i] << ' ';

		if (i % 6 == 0)plik << "\n"; // wiersze powinny mieć max 60 zn
	}

}
