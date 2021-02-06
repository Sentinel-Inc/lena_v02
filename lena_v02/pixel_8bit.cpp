// plik zawiera definicje dla funkcji zadeklarowanych w pixel_8bit.h
//
//
//autor : Piotr Drabik							data: 14.12.2020
//logi  :
//opis  :										data:
//
//

#include "pixel_8bit.h"

pixel_8bit::pixel_8bit(unsigned char color)
{

	this->color = color;

}

pixel_8bit::pixel_8bit(const pixel_8bit& other)
{

	this->color = other.color;

}

pixel_8bit& pixel_8bit::operator=(const pixel_8bit& other)
{
	if (this == &other) return *this; // na wypadek "a=a" 

	this->color = other.color;


	return *this;

}

unsigned pixel_8bit::gen_hash()
{
	return color;
}

unsigned pixel_8bit::gen_hash(const unsigned& max_color)
{

	//max_color doesn't change a thing
	return color;
}

unsigned char pixel_8bit::get_color()
{ 
	return color; 
}



void pixel_8bit::set_color(unsigned char color)
{
	this->color = color;
}
