
#pragma once 
#ifndef PPM_H
#define PPM_H
#include <vector>
#include <fstream>
#include "obraz.h"
#include "_24bit_pixel.h"
#include "file_exception.h"

class ppm : public obraz
{
public:
	// objekt nie potrzebuje konstruktora bezparametrowego 
	ppm() = delete;

	ppm(std::string);
	ppm(const ppm&);

	ppm& operator=(const ppm&);

private:
	
	unsigned char check_color(int);
	format read_header(std::fstream&);


protected:

	std::vector<_24bit_pixel> image;
	size_t x, y;
	int max_color;

};
#endif
