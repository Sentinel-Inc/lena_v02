#include "obraz.h"

exception::invalid_file_format_exception invalid_file_format;
exception::invalid_character_exception invalid_character;
exception::bad_dimentions_exception bad_dimentions;


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
