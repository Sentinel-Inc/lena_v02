// plik zawiera definicje dla funkcji zadeklarowanych w _24bit_pixel.h
//
//
//autor : Piotr Drabik							data: 14.12.2020
//logi  :
//opis  :										data:
//
//

#include "_24bit_pixel.h"


_24bit_pixel::_24bit_pixel(unsigned char r, unsigned char g, unsigned char b) :this->r(r), this->g(g), this->b(b){}

_24bit_pixel::_24bit_pixel(const _24bit_pixel& other)
{

	this->r = other.r;
	this->g = other.g;
	this->b = other.b;
}

_24bit_pixel& _24bit_pixel::operator=(const _24bit_pixel& other)
{
	if (this == &other) return *this; // na wypadek "a=a" 

	this->r = other.r;
	this->g = other.g;
	this->b = other.b;

	return *this;

}


// max_collor okreœla maxymaln¹ wartoœæ koloru r lub g lub b

unsigned _24bit_pixel::gen_hash(const unsigned& max_color) {
	return r * (max_color + 1) * (max_color + 1) + g * (max_color + 1) + b;
};
