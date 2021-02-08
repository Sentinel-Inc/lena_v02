// obraz klasa interfejs dla dlas pbm, pgm, ppm 
// nie mozna utwozyc obiektu tej klasy!
#pragma once
#ifndef OBRAZ_H
#define OBRAZ_H
#include <string>
#include <vector>
#include <fstream>

#include "file_exception.h"



 const enum format {
	ascii = 0,
	binary = 1
};

class obraz
{
public:
	virtual size_t get_x() = 0;
	virtual size_t get_y() = 0;
	virtual size_t size() = 0;
	virtual unsigned get_max_color() = 0;
	virtual unsigned number_of_color_dimentions() = 0;
	virtual unsigned get_pixel_hash(size_t ) = 0;


public:
	


};





#endif //! OBRAZ_H
