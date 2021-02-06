// klasa _24_bit_pixel przecowywuje kolor pixela w rozdzielczo��i true collor
// czyli na ka�dy pixel na zdj�ciu po�wi�cane s� 3 bajty informacji 
// pozwala to na uzyskanie 16777216 kolor�w 
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

#include<iostream>
class pixel_24bit
{
public:

	pixel_24bit() :r(0), g(0), b(0) {};

	pixel_24bit(unsigned char r, unsigned char g, unsigned char b) :r(r), g(g), b(b) {};


	// konstruktor kopiujacy i operator = sa tworzone za nas 

	//pixel_24bit(const pixel_24bit&);

	//pixel_24bit& operator=(const pixel_24bit&);


	// gen_hash przelicza kombinaj� liczb r, g ,b i generuje pojedy�cz� warto�� unikaln� dla tej kombinacji

	unsigned gen_hash(const unsigned&);

	unsigned char get_r() { return r; }

	unsigned char get_g() { return g; }

	unsigned char get_b() { return b; }


	void set_all(const unsigned char& r, const unsigned char& g, const unsigned char& b) {
		this->r = r; 
		this->g = g;
		this->b = b;
	}

	void set_r(unsigned char r) { this->r = r; }

	void set_g(unsigned char g) { this->g = g; }

	void set_b(unsigned char b) { this->b = b; }

	friend std::ostream& operator << (std::ostream& out, const pixel_24bit& color)
	{
		out << (int)color.r<<' '<< (int)color.g<<' '<< (int)color.b;
		return out;
	}


protected:
	unsigned char r, g, b;
	// warto��i r,g,b w jako�ci true collor mog� nale�e� do zakresu 0 - 255 



};

#endif // !_24BIT_PIXEL_H