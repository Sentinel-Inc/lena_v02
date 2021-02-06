
#pragma once
#ifndef OBRAZ_H
#define OBRAZ_H
#include <string>
#include <vector>
#include <fstream>

#include "file_exception.h"



static const enum format {
	ascii = 0,
	binary = 1
};

class obraz
{
public:
	virtual size_t get_x() { return  x; }
	virtual size_t get_y() { return  y; }
	virtual size_t size() { return x*y; }
	virtual unsigned get_max_color() { return max_color; }
	virtual unsigned number_of_color_dimentions() { return 0; } 
	virtual unsigned get_pixel_hash(unsigned position) { return 0; }


public:
	obraz():x(NULL),y(NULL),max_color(NULL){};
	obraz(size_t height,size_t width,unsigned max_color) :x(height), y(width), max_color(max_color) {};
protected:

	size_t x; // height
	size_t y; // width
	unsigned max_color; // max_color veluestored by one pixel 

};





#endif //! OBRAZ_H
