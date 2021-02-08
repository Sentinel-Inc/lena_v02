// rozszerzenie funkcjonalnosci klasy obraz
// pozwala na odczyt plików .ppm
// informacje o poszczegulnych pixelach buduj¹cych wczytywany obraz
// znajduj¹ siê w polu image 

//autor : Piotr Drabik							data: 14.12.2020
//logi  :
//opis  :										data:
//
//


#pragma once 
#ifndef PPM_H
#define PPM_H

#include "obraz.h"
#include "pixel_24bit.h"
extern bool is_comment(const char&);

class ppm : public obraz
{
public:

	ppm() = delete;

	ppm(std::string);
	ppm(const ppm&);

	ppm& operator=(const ppm&);
	

	void read_data_from_file(std::string);
	void save_data_to_file(std::string);
	size_t get_x() { return  x; }
	size_t get_y() { return  y; }
	size_t size() { return x*y; }
	unsigned get_max_color() { return max_color; }

	unsigned number_of_color_dimentions() { return 3; } // numer wymiarów potrzebnych do zapisania pojedyñczego koloru
	unsigned get_pixel_hash(size_t position) { return image[position].gen_hash(max_color); }

	void set_pixel(size_t , size_t ,  pixel_24bit );

private:

	unsigned char check_color(int);
	format read_header(std::fstream&);


protected:

	std::vector<pixel_24bit> image;

	size_t x; // height
	size_t y; // width
	unsigned max_color; // max_color veluestored by one pixel 


};
#endif
