// plik zawiera definicje dla funkcji zadeklarowanych w _8bit_pixel.h
//
//
//autor : Piotr Drabik							data: 14.12.2020
//logi  :
//opis  :										data:
//
//

#include "_8bit_pixel.h"

_8bit_pixel::_8bit_pixel(unsigned char color)
{

	this->color = color;

}

_8bit_pixel::_8bit_pixel(const _8bit_pixel& other)
{

	this->color = other.color;

}

_8bit_pixel& _8bit_pixel::operator=(const _8bit_pixel& other)
{
	if (this == &other) return *this; // na wypadek "a=a" 

	this->color = other.color;


	return *this;

}

unsigned _8bit_pixel::gen_hash()
{
	return color;
}

unsigned char _8bit_pixel::get_color()
{ 
	return color; 
}



void _8bit_pixel::set_color(unsigned char color)
{
	this->color = color;
}
