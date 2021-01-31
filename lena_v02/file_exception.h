// definicje wyj�tk�w wyst�puj�chych przy wczytywaniu danych z plik�w
// jako �e wyj�tki mog� by� spowodowane tylko wadliwym plikiem
// nigdzie w funkcjach wyj�tki nie s� �apane 
//
//
//autor : Piotr Drabik							data: 14.12.2020
//logi  :
//opis  :										data:
//
//


#pragma once
#ifndef FILE_EXCEPTION_H
#define FILE_EXCEPTION_H
#include <exception>
namespace exception {

	class file_error_exception : public  std::exception
	{
	public:
		const char* what() const throw () { // b��d pliku 
			return "file error";
		}



	};

	class bad_dimentions_exception : public  file_error_exception {
	public:
		const char* what() const throw () {
			return "invalid image dimentions";// niew�a�ciwy rozmiar pliku
		}
	};




	class invalid_path_exception : public  file_error_exception {
	public:
		const char* what() const throw () { // niew�a�ciwa �cie�ka, lub niew�a�ciwe rozszerzenie pliku
			return "invalid image path";
		}
	};



	class invalid_file_format_exception : public  file_error_exception {
	public:
		const char* what() const throw () { // niew�a�ciwy nag��wek pliku
			return "invalid file format";
		}
	};



	class invalid_character_exception : public  file_error_exception {
	public:
		const char* what() const throw () { //nieporz�dany znak
			return "unexpected caracter occured";
		}
	};

	class not_implemented_file_format_exception : public  file_error_exception {
	public:
		const char* what() const throw () { // niezaimplementowany nag��wek 
			return "not implemented file format";
		}
	};


}
#endif // !FILE_EXCEPTION_H
