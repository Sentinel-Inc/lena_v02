// rozszerzenie funkcjonalnosci klasy obraz
// pozwala na odczyt plik�w .pgm
// informacje o poszczegulnych pixelach buduj�cych wczytywany obraz
// znajduj� si� w polu image 

//autor : Piotr Drabik							data: 14.12.2020
//logi  :
//opis  :										data:
//
//

#pragma once
#ifndef PBM_H
#define PBM_H
#include "obraz.h"


#include "pixel_8bit.h"
class pbm :public obraz {
public:

	pbm() = delete;

	pbm(std::string);
	pbm(const pbm&);

	pbm& operator=(const pbm&);
	size_t get_x() { return  x; }
	size_t get_y() { return  y; }
	size_t size() { return x * y; }
	void read_data_from_file(std::string);
	void save_data_to_file(std::string);
	unsigned number_of_color_dimentions() { return 1; }
	unsigned get_max_color() { return max_color; }

	unsigned get_pixel_hash(unsigned position) { return image[position].gen_hash(max_color); }

	void set_pixel(size_t, size_t, pixel_8bit);

private:

	unsigned char check_color(int);
	format read_header(std::fstream&);



protected:
	std::vector<pixel_8bit> image; // image of a picture 


};


#endif // PBM_H