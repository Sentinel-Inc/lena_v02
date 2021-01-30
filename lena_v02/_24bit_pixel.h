// klasa _24_bit_pixel przecowywuje kolor pixela w rozdzielczoœæi true collor
// czyli na ka¿dy pixel na zdjêciu poœwiêcane s¹ 3 bajty informacji 
// pozwala to na uzyskanie 16777216 kolorów 
//
//
//autor : Piotr Drabik							data: 14.12.2020
//logi  :
//opis  :										data:
//
//
#pragma once
#ifndef _24BIT_PIXEL_H
#define _24BIT_PIXEL_H
#include <cmath>
class _24bit_pixel
{
	//ze  wzglêdu na karakteruystykê klasy,
	//konstruktor kopiuj¹cy wraz z destruktorem tworz¹ siê automatycznie
	//z tego powodu celowo ich nie deklarujê 

public:
	
	_24bit_pixel():r(0),g(0),b(0) {};

	_24bit_pixel(unsigned char, unsigned char, unsigned char);


	_24bit_pixel(const _24bit_pixel&);

	_24bit_pixel& operator=(const _24bit_pixel&);


	// gen_hash przelicza kombinajê liczb r, g ,b i generuje pojedyñcz¹ wartoœæ unikaln¹ dla tej kombinacji
	
	unsigned gen_hash(const unsigned&);

	unsigned char get_r() { return r; }

	unsigned char get_g() { return g; }

	unsigned char get_b() { return b; }

	void set_r(unsigned char r) { this->r = r; }

	void set_g(unsigned char g) { this->g = g; }

	void set_b(unsigned char b) { this->b = b; }



protected:
	unsigned char r, g, b; 
	// wartoœæi r,g,b w jakoœci true collor mog¹ nale¿eæ do zakresu 0 - 255 
	


};

#endif // !_24BIT_PIXEL_H