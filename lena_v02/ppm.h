
#pragma once 
#ifndef PPM_H
#define PPM_H

#include "obraz.h"
#include "_24bit_pixel.h"
extern bool is_comment(const char&);

class ppm : public obraz
{
public:

	ppm() :obraz() {};

	ppm(std::string);
	ppm(const ppm&);

	ppm& operator=(const ppm&);
	size_t get_x() { return  x; }
	size_t get_y() { return  y; }
	size_t size() { return x*y; }
	unsigned number_of_color_dimentions() { return 3; }
	unsigned get_max_color() { return max_color; }
	unsigned get_pixel_hash(unsigned position) { return image[position].gen_hash(max_color); }

private:

	unsigned char check_color(int);
	format read_header(std::fstream&);


protected:

	std::vector<pixel_24bit> image;
	

};
#endif
