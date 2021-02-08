#include "pbm.h"


exception::bad_dimentions_exception bad_dimentions_pbm;
exception::invalid_path_exception invalid_path_pbm;
exception::invalid_file_format_exception invalid_file_format_pbm;
exception::invalid_character_exception invalid_character_pbm;
exception::not_implemented_file_format_exception not_implemented_file_format_pbm;

extern bool is_comment(const char&);
extern void ignore_comment(std::fstream&);
extern void handle_char(std::fstream&);
extern int read_number(std::fstream&);

pbm::pbm(const pbm& other)
{
	image = other.image;
	x = other.x;
	y = other.y;
	max_color = other.max_color;
}

pbm& pbm::operator=(const pbm& other)
{

	if (this == &other) return *this;
	image = other.image;
	x = other.x;
	y = other.y;
	max_color = other.max_color;
	return *this;
}




void pbm::set_pixel(size_t x, size_t y, pixel_8bit new_color)
{
	image[x * this->x + y] = new_color;
}

unsigned char pbm::check_color(int color) {
	if (color < 0 || color> max_color) {
		throw invalid_file_format_pbm;
	}
	else return (unsigned char)color;


}


format pbm::read_header(std::fstream& plik) {
	char letter;
	do {

		plik >> letter;
		if (is_comment(letter)) ignore_comment(plik);// w przypadu gdy napotkamy '#' czyli poczatek komentarza

		else if (letter == 'P') {
			plik >> letter;
			switch (letter) {
			case '1': return format(ascii);
				//wczytanie poprawnego naglowka (w tym przypadku P1)koonczy zadanie funkcji 

			case '4': return format(binary);
				//zwracany jest format w jakim zapisane sa dane w pliku

			default:
				//niepoprawne rozszerzenie pliku
				// lub napotkano na nioczekiwany symbol 

				throw invalid_file_format_pbm;
				break;
			}

		}
		else {
			//napotkano nioczekiwany symbol
			throw invalid_character_pbm;
		}

	} while (!plik.eof());
	throw invalid_file_format_pbm;
	// nie znaleziono naglowka pliku 

}

pbm::pbm(std::string file_path) {

	read_data_from_file(file_path);

}



void pbm::read_data_from_file(std::string file_path)
{

	std::fstream plik;
	plik.open(file_path, std::ios::in);
	if (plik.good()) {

		if (read_header(plik) == format(ascii)) {


			x = read_number(plik);

			if (x < 0) { throw bad_dimentions_pbm; }//wysokosc musi byc nieujemna


			y = read_number(plik);


			if (y < 0) { throw bad_dimentions_pbm; }// szerokosc  musi byc nieujemna

			size_t array_size = y * x; // tymczasowa  zmienna

			if (!image.empty()) image.clear(); // je¿eli obraz posiada ju¿ dane 
							  // nale¿y je nadpisaæ 
			image.reserve(array_size);



			for (unsigned i = 0; i < array_size; i++) {

				if (plik.eof()) { throw bad_dimentions_pbm; } //   nizgodny rozmiar pliku z zadeklarowanym rozmiarem zdjecia

				unsigned char color = check_color(read_number(plik));


				image.push_back({ color });//dodaje pobrany kolor do tablicy


			}

		}
		else {
			// nie zaiplementowany format pliku w tym, przypadku p6
			throw  not_implemented_file_format_pbm;
		}
	}
	else {
		// nie znaleziono pliku pod podanym adresem lub napodkano problem z odczytaniem danych z niego
		//wiecej pod adresem: https://en.cppreference.com/w/cpp/io/basic_ios/good

		throw invalid_path_pbm;
	}
}

void pbm::save_data_to_file(std::string file_path)
{

	std::fstream plik;
	plik.open(file_path, std::ios::out);
	plik << "P1\n";
	plik << x << "\n";
	plik << y << "\n";
	plik << "#generated with lena_vo2";
	for (int i = 0; i < size() ; i++) {
		plik << image[i] << ' ';

		if (i % 6 == 0)plik << "\n"; // wiersze powinny mieæ max 60 znaków  
	}

}
