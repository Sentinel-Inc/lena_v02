
#pragma once
#ifndef PGM_H
#define PGM_H
#include "obraz.h"
class pgm() :public obraz {
public:



	format read_header(std::fstream&);


protected:
	_8bit_pixel* image; 


}


#endif // PGM_H