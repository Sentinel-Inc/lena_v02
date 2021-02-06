
#pragma once
#ifndef PGM_H
#define PGM_H
#include "obraz.h"


#include "pixel_8bit.h"
class pgm:public obraz {
public:

	pgm() = delete;

	pgm(std::string);
	pgm(const pgm&);

	pgm& operator=(const pgm&);
	size_t get_x() { return  x; }
	size_t get_y() { return  y; }
	size_t size() { return x * y; }
	void read_data_from_file(std::string);
	unsigned number_of_color_dimentions() { return 1; }
	unsigned get_max_color() { return max_color; }

	unsigned get_pixel_hash(unsigned position) { return image[position].gen_hash(max_color); }

	void set_pixel(size_t , size_t , pixel_8bit );

private:

	unsigned char check_color(int);
	format read_header(std::fstream&);



protected:
	std::vector<pixel_8bit> image; // image of a picture 


};


#endif // PGM_H